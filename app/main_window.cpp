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


    m_mainLay->addWidget(m_topBarWidget, 1, Qt::AlignTop);
    m_mainLay->addLayout(m_bodyStackedLay);
    setLayout(m_mainLay);

    /* Connections */
}

MainWindow::~MainWindow()
{
}

