
#include <QDebug>
#include <QFontDatabase>

#include "Library_Page.h"

LibraryPage::LibraryPage(QWidget *parent)
    : QWidget{parent}
{
    m_mainLay = new QVBoxLayout;
    m_mainLay->setContentsMargins(20, 30, 20, 30);
    m_mainLay->setSpacing(30);
    setLayout(m_mainLay);

    m_gridLay = new QGridLayout;
    m_gridLay->setSpacing(30);
    m_scrollWidget = new QWidget(this);
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setWidget(m_scrollWidget);
    m_scrollWidget->setLayout(m_gridLay);
    m_gridLay->setSizeConstraint(QLayout::SetMaximumSize);

    // Fill up
    for (int r = 0; r < 1; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            GameTile *tile = new GameTile;
            //tile->setObjectName("gametile");
            //tile->setMaximumSize(368, 350);
            //QSizePolicy qsp(QSizePolicy::Preferred, QSizePolicy::Preferred);
            //qsp.setHeightForWidth(true);
            //tile->setSizePolicy(qsp);
            tile->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
            //tile->setFixedWidth(640);
            //tile->setFixedSize(368, 350);
            m_gridLay->addWidget(tile, r, c, Qt::AlignHCenter);
        }
    }

    m_pageTitleLbl = new QLabel("My Library", this);
    m_pageTitleLbl->setObjectName("pgtitle");

    m_mainLay->addWidget(m_pageTitleLbl, 0, Qt::AlignLeft | Qt::AlignTop);
    m_mainLay->addWidget(m_scrollArea);
}

