
#include "Game_Tile.h"

GameTile::GameTile(QWidget *parent)
    : QWidget{parent}
{
    m_mainLay = new QVBoxLayout;
    //m_mainLay->setContentsMargins(0, 0, 0, 0);
    //m_mainLay->setSpacing(0);

    m_gameCoverPixmap = QPixmap("../app/resources/game-cover.png");

    m_gameCoverLbl = new QLabel(this);
    m_gameCoverLbl->setPixmap(m_gameCoverPixmap);
    m_gameTitleLbl = new QLabel("Dark Story", this);

    m_mainLay->addWidget(m_gameCoverLbl);
    m_mainLay->addWidget(m_gameTitleLbl);

    setStyleSheet("QWidget:hover {background: #161A1E;}");

    setObjectName("gametile");
    setLayout(m_mainLay);
}

void GameTile::setTitle(const QString &title)
{
    m_gameTitleLbl->setText(title);
}

void GameTile::setCover(QPixmap pixmap)
{
    m_gameCoverLbl->setPixmap(pixmap);
}

