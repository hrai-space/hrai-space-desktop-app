
#include "Top_Bar.h"

TopBar::TopBar(const QPixmap &logo, QWidget *parent)
    : QWidget{parent}, m_logoPixmap{logo}
{
    m_mainLay = new QHBoxLayout;
    m_mainLay->setContentsMargins(0, 0, 0, 0);
    m_mainLay->setSpacing(50);
    setLayout(m_mainLay);

    m_logoPixmap = m_logoPixmap.scaledToHeight(30, Qt::SmoothTransformation);

    m_logoBtn = new QPushButton(this);
    m_logoBtn->setObjectName("logobtn");
    //m_logoLbl->setText(".space");
    //m_logoLbl->setAlignment(Qt::AlignCenter);
    m_logoBtn->setFixedSize(160, 43);
    m_logoBtn->setIcon(m_logoPixmap);
    m_logoBtn->setIconSize(m_logoBtn->size());

    //m_findTxtEdit = new QLineEdit(this);
    //m_findTxtEdit->setPlaceholderText("Пошук ігор");

    QPixmap default_avatar_pixmap = QPixmap(":/ava.png");

    m_profileBtn = new PictureWidget(0, this);
    m_profileBtn->setRatio(1, 1);
    m_profileBtn->setPixmap(default_avatar_pixmap);
    m_profileBtn->setObjectName("profile");
    m_profileBtn->scaleToHeight(50);
    m_profileBtn->setCornerRadius(50/2.0, 50/2.0);


    m_mainLay->addWidget(m_logoBtn);
    //m_mainLay->addWidget(m_findTxtEdit, 1, Qt::AlignRight);
    m_mainLay->addWidget(m_profileBtn, 0, Qt::AlignRight);

    connect(m_profileBtn, &QPushButton::released, this, &TopBar::openLogInPopup);
    connect(m_logoBtn, &QPushButton::released, this, &TopBar::backToLibraryPage);
}

void TopBar::setAvatar(const QString &link)
{
    m_profileBtn->loadPixmapFromWeb(link);
    m_profileBtn->scaleToHeight(50);
}

