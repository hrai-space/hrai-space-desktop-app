
#include "Library_Page.h"

LibraryPage::LibraryPage(QWidget *parent)
    : QWidget{parent}
{
    m_mainLay = new QVBoxLayout;
    m_mainLay->setContentsMargins(20, 30, 20, 30);
    m_mainLay->setSpacing(30);
    setLayout(m_mainLay);

    m_gridLay = new QGridLayout;
    m_scrollWidget = new QWidget(this);
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setWidget(m_scrollWidget);
    m_scrollWidget->setLayout(m_gridLay);

    // Fill up
    for (int r = 0; r < 100; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            GameTile *tile = new GameTile(this);
            tile->setObjectName("gametile");
            m_gridLay->addWidget(tile, r, c, Qt::AlignHCenter);
        }
    }

    QLabel *page_title_lbl = new QLabel("My Library", this);
    page_title_lbl->setObjectName("pgtitle");

    m_mainLay->addWidget(page_title_lbl, 0, Qt::AlignLeft | Qt::AlignTop);
    m_mainLay->addWidget(m_scrollArea);
}

