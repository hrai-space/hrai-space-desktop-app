
#include <QDebug>

#include "Game_Page.h"

GamePage::GamePage(QWidget *parent)
    : QWidget{parent}
{
    m_mainLay = new QVBoxLayout;
    m_mainLay->setContentsMargins(20, 30, 20, 30);
    m_mainLay->setSpacing(30);
    setLayout(m_mainLay);

    m_mainScrollLay = new QVBoxLayout;
    m_mainScrollLay->setSizeConstraint(QLayout::SetMinimumSize);
    m_centralWidget = new QWidget(this);
    m_mainScrollArea = new QScrollArea(this);
    m_mainScrollArea->setWidgetResizable(true);
    //m_mainScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_mainScrollArea->setWidget(m_centralWidget);
    m_centralWidget->setLayout(m_mainScrollLay);

    m_mainLay->addWidget(m_centralWidget);


    /* Screenshots area */
    m_screenshotsGridLay = new QGridLayout;
    m_screenshotsGridLay->setSpacing(30);
    m_screenshotsScrollWidget = new QWidget(this);
    m_screenshotsScrollArea = new QScrollArea(this);
    //m_screenshotsScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //m_screenshotsScrollArea->setWidgetResizable(true);
    m_screenshotsScrollArea->setWidget(m_screenshotsScrollWidget);
    m_screenshotsScrollWidget->setLayout(m_screenshotsGridLay);
    //m_screenshotsGridLay->setSizeConstraint(QLayout::SetMaximumSize);


    m_screenshotPixmap = QPixmap("../app/resources/pubg.jpg");
    m_screenshotLbl = new QLabel(this);
    m_screenshotLbl->setPixmap(m_screenshotPixmap);

    m_gameTitleLbl = new QLabel("Dark Story", this);
    m_gameTitleLbl->setObjectName("pgtitle");

    //m_descriptionTxt = new QLabel("Hello, world!", this);
//    m_descriptionTxt->setTextInteractionFlags(Qt::TextSelectableByMouse);
//    m_descriptionTxt->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
//    for (int var = 0; var < 50; ++var)
//    {
//        m_descriptionTxt->setText(m_descriptionTxt->text() + QString("Hello\n"));
//    }


    m_mainScrollLay->addWidget(m_screenshotLbl, 0, Qt::AlignTop);
    m_mainScrollLay->addWidget(m_screenshotsScrollArea);
    m_mainScrollLay->addWidget(m_gameTitleLbl, 0, Qt::AlignLeft | Qt::AlignTop);
    //m_mainScrollLay->addWidget(m_descriptionTxt, 1);

    for (int var = 0; var < 50; ++var)
    {
        m_descriptionTxt = new QLabel("Hello, world!", this);
        m_mainScrollLay->addWidget(m_descriptionTxt, 1);
    }

}

