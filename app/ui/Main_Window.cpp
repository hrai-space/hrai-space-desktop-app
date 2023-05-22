
#include <QResizeEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QFile>

#include "Main_Window.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), m_networkManager(new NetworkManager(this))
{
    installEventFilter(this);
    m_mainLay = new QVBoxLayout;
    m_mainLay->setContentsMargins(35, 32, 35, 32);
    m_mainLay->setSpacing(25);

    m_logoPixmap = QPixmap(":/logo.svg");
    m_logoFullPixmap = QPixmap(":/logo-full.svg");

    /* Top bar */
    m_topBarWidget = new TopBar(m_logoPixmap, this);

    /* Body area */
    m_bodyStackedLay = new QStackedLayout;
    //m_bodyStackedLay->setContentsMargins(0, 0, 0, 0);
    //m_bodyStackedLay->setSpacing(0);

    m_libraryPage = new LibraryPage(this);
    m_bodyStackedLay->addWidget(m_libraryPage);
    //m_gamePage = new GamePage(this);
    //m_gamePage->setObjectName("gamepg");
    //m_bodyStackedLay->addWidget(m_gamePage);
    //m_bodyStackedLay->setCurrentIndex(0);


    m_mainLay->addWidget(m_topBarWidget, 0, Qt::AlignTop);
    m_mainLay->addLayout(m_bodyStackedLay);
    setLayout(m_mainLay);

    /* Lpg In popup */
    m_logInPopup = new LoginPopup(m_logoFullPixmap, this);
    m_logInPopup->hide();
    m_logInPopup->setObjectName("popup");
    m_logInPopup->setGeometry(200, 100, 400, 402);

    /* Connections */
    connect(m_topBarWidget, &TopBar::openLogInPopup, this, &MainWindow::openLogInPopup);
    connect(m_topBarWidget, &TopBar::backToLibraryPage, this, &MainWindow::backToLibraryPage);
    //connect(m_topBarWidget, &TopBar::reloadLibraryPage, this, &MainWindow::reloadLibraryPage);
    connect(m_networkManager, &NetworkManager::responseGameLibrary, m_libraryPage, &LibraryPage::fillGameLibrary);
    connect(m_logInPopup, &LoginPopup::requestLogin, m_networkManager, &NetworkManager::requestLogin);
    connect(m_networkManager, &NetworkManager::responseLogin, this, &MainWindow::responseLogin);
    connect(m_libraryPage, &LibraryPage::requestGame, m_networkManager, &NetworkManager::requestGame);
    connect(m_networkManager, &NetworkManager::responseGame, this, &MainWindow::openGamePage);

    QFile user_data_file("userdata");
    if (user_data_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&user_data_file);
        QString login = in.readLine();
        QString password = in.readLine();
        m_logInPopup->setLoginData(login, password);
        m_networkManager->requestLogin(login, password);
        user_data_file.close();
    }
    else
    {
        m_logInPopup->show();
    }
}

MainWindow::~MainWindow()
{
    delete m_networkManager;
}

void MainWindow::openLogInPopup()
{
    if (m_logInPopup->isHidden())
    {
        m_logInPopup->show();
        m_logInPopup->raise();
    }
    else
        m_logInPopup->hide();
}

void MainWindow::responseLogin(const User *user)
{
    if (user->id() == 0)
        return;
    backToLibraryPage();
    m_topBarWidget->setAvatar(user->avatartLink());
    QFile user_data_file("userdata");
    if (user_data_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&user_data_file);
        out << user->login() << "\n" << user->password();
    }
}

void MainWindow::backToLibraryPage()
{
    /* Remove last opened GamePage */
    QLayoutItem *child;
    for (int i = 1; i < m_bodyStackedLay->count(); ++i)
    {
        child = m_bodyStackedLay->takeAt(i);
        delete child->widget();
        delete child;
    }
    /* Request from website */
    if (m_bodyStackedLay->currentIndex() == 0)
    {
        m_networkManager->requestGameLibrary();
        m_logInPopup->hide();
    }
    m_bodyStackedLay->setCurrentIndex(0);
}

void MainWindow::openGamePage(const Game *game)
{
    GamePage *game_page = new GamePage(game, this);
    game_page->setObjectName("gamepg");
    m_bodyStackedLay->addWidget(game_page);
    m_bodyStackedLay->setCurrentIndex(m_bodyStackedLay->count()-1);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
        QPoint mouse_pos = mouse_event->pos();
        // Log In Popup hide
        QRect widget_rect = m_logInPopup->geometry();
        if(!widget_rect.contains(mouse_pos))
            m_logInPopup->hide();
    }
    return QObject::eventFilter(obj, event);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    // Recalculate LogInPopup position
    QPoint popup_pos = QPoint(event->size().width() / 2 - m_logInPopup->size().width() / 2,
                              event->size().height() / 2 - m_logInPopup->size().height() / 2);
    m_logInPopup->move(popup_pos);
}

