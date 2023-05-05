
#include "Library_Page.h"

LibraryPage::LibraryPage(QWidget *parent)
    : QWidget{parent}
{
    m_mainLay = new QVBoxLayout;
    //m_mainLay->setContentsMargins(0, 0, 0, 0);
    //m_mainLay->setSpacing(0);
    setLayout(m_mainLay);

    m_gridLay = new QGridLayout;
    m_scrollWidget = new QWidget(this);
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setWidget(m_scrollWidget);
    m_scrollWidget->setLayout(m_gridLay);

    for (int r = 0; r < 100; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            m_gridLay->addWidget(new QLabel("Search games", this), r, c);
        }
    }

    QLabel *l = new QLabel("Library", this);

    m_mainLay->addWidget(l, 1, Qt::AlignLeft | Qt::AlignTop);
    m_mainLay->addWidget(m_scrollArea);
}

