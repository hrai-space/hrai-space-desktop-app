
#include <QResizeEvent>

#include "Main_Window.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_mainLay = new QVBoxLayout;
    m_mainLay->setContentsMargins(45, 32, 45, 32);

    /* Top bar */
    m_topBarWidget = new TopBar(this);


    /* Body area */
    m_bodyStackedLay = new QStackedLayout;
    //m_bodyStackedLay->setContentsMargins(0, 0, 0, 0);
    //m_bodyStackedLay->setSpacing(0);

    m_libraryPage = new LibraryPage(this);
    m_bodyStackedLay->addWidget(m_libraryPage);


    m_mainLay->addWidget(m_topBarWidget, 0, Qt::AlignTop);
    m_mainLay->addLayout(m_bodyStackedLay);
    setLayout(m_mainLay);

    /* Lpg In popup */
    m_logInPopup = new LoginPopup(this);
    m_logInPopup->hide();
    m_logInPopup->setObjectName("popup");
    m_logInPopup->setGeometry(200, 100, 400, 352);
    //m_logInPopup->setStyleSheet(".QWidget {background: #161A1E; border: 1px solid #214AD8; border-radius: 10px;}");

    /* Connections */
    connect(m_topBarWidget, &TopBar::openLogInPopup, this, &MainWindow::openLogInPopup);
}

MainWindow::~MainWindow()
{
}

void MainWindow::openLogInPopup()
{
    if (m_logInPopup->isHidden())
        m_logInPopup->show();
    else
        m_logInPopup->hide();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    QPoint popup_pos = QPoint(event->size().width() / 2 - m_logInPopup->size().width() / 2,
                              event->size().height() / 2 - m_logInPopup->size().height() / 2);
    m_logInPopup->move(popup_pos);
}

