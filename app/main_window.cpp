#include "main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_mainLay = new QGridLayout(this);
    m_mainLay->setContentsMargins(10, 20, 10, 20);
    m_mainLay->setSpacing(20);


    /* Connections */
}

MainWindow::~MainWindow()
{
}

