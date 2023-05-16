
#include <QResizeEvent>
#include <QMouseEvent>
#include <QDebug>

#include "Main_Window.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    installEventFilter(this);
    m_mainLay = new QVBoxLayout;
    m_mainLay->setContentsMargins(35, 32, 35, 32);
    m_mainLay->setSpacing(25);

    m_logoPixmap = QPixmap(":/logo.svg");

    /* Top bar */
    m_topBarWidget = new TopBar(m_logoPixmap, this);


    /* Body area */
    m_bodyStackedLay = new QStackedLayout;
    //m_bodyStackedLay->setContentsMargins(0, 0, 0, 0);
    //m_bodyStackedLay->setSpacing(0);

    m_libraryPage = new LibraryPage(this);
    m_bodyStackedLay->addWidget(m_libraryPage);
    m_gamePage = new GamePage(this);
    m_gamePage->setObjectName("gamepg");
    m_bodyStackedLay->addWidget(m_gamePage);
    m_bodyStackedLay->setCurrentIndex(1);


    m_mainLay->addWidget(m_topBarWidget, 0, Qt::AlignTop);
    m_mainLay->addLayout(m_bodyStackedLay);
    setLayout(m_mainLay);

    /* Lpg In popup */
    m_logInPopup = new LoginPopup(m_logoPixmap, this);
    m_logInPopup->hide();
    m_logInPopup->setObjectName("popup");
    m_logInPopup->setGeometry(200, 100, 400, 402);

    /* Connections */
    connect(m_topBarWidget, &TopBar::openLogInPopup, this, &MainWindow::openLogInPopup);
    connect(m_topBarWidget, &TopBar::backToLibraryPage, this, &MainWindow::backToLibraryPage);
}

MainWindow::~MainWindow()
{
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

void MainWindow::backToLibraryPage()
{
    m_bodyStackedLay->setCurrentIndex(0);
    m_logInPopup->hide();
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
    // Recalculate Log In popup position
    QPoint popup_pos = QPoint(event->size().width() / 2 - m_logInPopup->size().width() / 2,
                              event->size().height() / 2 - m_logInPopup->size().height() / 2);
    m_logInPopup->move(popup_pos);
}

