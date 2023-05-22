
#include <QDebug>
#include <QFontDatabase>

#include "Game_Tile.h"
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

    m_pageTitleLbl = new QLabel("Бібліотека", this);
    m_pageTitleLbl->setObjectName("pgtitle");

    m_mainLay->addWidget(m_pageTitleLbl, 0, Qt::AlignLeft | Qt::AlignTop);
    m_mainLay->addWidget(m_scrollArea);
}

void LibraryPage::fillGameLibrary(const QHash<int, Game *> &gameLibrary)
{
    clearGameLibrary();
    int row = 0, col = 0;
    foreach (auto game, gameLibrary)
    {
        GameTile *tile = new GameTile(game->title(), game->id(), game->iconLink(), this);
        tile->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        connect(tile, &GameTile::opened, this, [this](int id)
                {
                    emit requestGame(id);
                });
        m_gridLay->addWidget(tile, row, col, Qt::AlignHCenter);
        if (col < 2)
            col++;
        else
        {
            col = 0;
            row++;
        }
    }
}

void LibraryPage::clearGameLibrary()
{
    QLayoutItem *child;
    while ((child = m_gridLay->takeAt(0)) != nullptr)
    {
        delete child->widget();
        delete child;
    }
}


