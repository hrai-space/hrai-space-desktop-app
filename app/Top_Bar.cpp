
#include "Top_Bar.h"

TopBar::TopBar(QWidget *parent)
    : QWidget{parent}
{
    m_mainLay = new QHBoxLayout;
    m_mainLay->setContentsMargins(0, 0, 0, 0);
    m_mainLay->setSpacing(50);
    setLayout(m_mainLay);

    m_logoPixmap = QPixmap(":/logo.svg");
    m_logoPixmap = m_logoPixmap.scaledToWidth(80, Qt::SmoothTransformation);

    m_avatarPixmap = QPixmap(":/ava.png");
    m_avatarPixmap = m_avatarPixmap.scaledToWidth(35, Qt::SmoothTransformation);

    m_logoLbl = new QLabel(this);
    m_logoLbl->setObjectName("logolbl");
    //m_logoLbl->setText(".space");
    m_logoLbl->setAlignment(Qt::AlignCenter);
    m_logoLbl->setFixedSize(144, 43);
    m_logoLbl->setPixmap(m_logoPixmap);

    m_findTxtEdit = new QLineEdit(this);
    //m_findTxtEdit->setFixedSize(200, 70);
    m_findTxtEdit->setPlaceholderText("Search games");

    m_profileLbl = new QLabel(this);
    m_profileLbl->setText("Profile");
    m_profileLbl->setPixmap(m_avatarPixmap);

    m_mainLay->addWidget(m_logoLbl);
    m_mainLay->addWidget(m_findTxtEdit, 1, Qt::AlignRight);
    m_mainLay->addWidget(m_profileLbl);
}

