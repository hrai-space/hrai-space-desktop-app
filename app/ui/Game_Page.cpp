
#include <QDebug>
#include <QPainter>

#include "Game_Page.h"

GamePage::GamePage(QWidget *parent)
    : QWidget{parent}
{
    m_mainLay = new QVBoxLayout;
    m_mainLay->setContentsMargins(0, 0, 0, 0);
    m_mainLay->setSpacing(0);

    m_mainScrollLay = new QVBoxLayout;
    //m_mainScrollLay->setSizeConstraint(QLayout::SetMaximumSize);
    m_mainScrollLay->setContentsMargins(0, 0, 0, 0);
    m_mainScrollLay->setSpacing(17);
    //m_mainScrollLay->setSizeConstraint(QLayout::SetMinimumSize);
    m_centralWidget = new QWidget(this);
    m_centralWidget->setObjectName("gamepg");
    //m_centralWidget->setStyleSheet("background: transparent;");
    m_mainScrollArea = new QScrollArea(this);
    m_mainScrollArea->setWidgetResizable(true);
    m_mainScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_mainScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_mainScrollArea->setWidget(m_centralWidget);
    m_centralWidget->setLayout(m_mainScrollLay);

    m_mainLay->addWidget(m_mainScrollArea);


    /* Screenshots area */
    m_screenshotsHBoxLay = new QHBoxLayout;
    //m_screenshotsHBoxLay->setSizeConstraint(QLayout::SetFixedSize);
    m_screenshotsHBoxLay->setContentsMargins(20, 0, 20, 0);
    //m_screenshotsHBoxLay->setSpacing(10);
    m_screenshotsScrollWidget = new QWidget(this);
    //m_screenshotsScrollWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_screenshotsScrollArea = new QScrollArea(this);
    //m_screenshotsScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_screenshotsScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_screenshotsScrollArea->setWidgetResizable(true);
    m_screenshotsScrollArea->setWidget(m_screenshotsScrollWidget);
    m_screenshotsScrollWidget->setLayout(m_screenshotsHBoxLay);
    //m_screenshotsScrollArea->setStyleSheet("border: solid 1px red;");
    m_screenshotsScrollArea->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_screenshotsScrollArea->setFixedHeight(200);
    //m_screenshotsScrollArea->setFixedWidth(200);
    //m_screenshotsScrollWidget->setFixedHeight(200);


    m_screenshotPixmap = QPixmap("../app/resources/pubg-1.jpg");

    for (int var = 0; var < 10; ++var)
    {
        PictureWidget *pict = new PictureWidget(this);
        pict->setCornerRadius(8.0, 8.0);
        pict->setPixmap(&m_screenshotPixmap);
        pict->scaleToHeight(170);
        //pict->setFixedSize(190, 107);
        //pict->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        m_screenshotsHBoxLay->addWidget(pict);
    }



    m_pictureWidget = new PictureWidget(this);
    m_pictureWidget->setCornerRadius(50.0, 50.0);
    m_pictureWidget->setPixmap(&m_screenshotPixmap);
    //m_pictureWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);

    m_gameTitleLbl = new QLabel("Dark Story", this);
    m_gameTitleLbl->setObjectName("pgtitle");
    m_gameTitleLbl->setTextInteractionFlags(Qt::TextSelectableByMouse);

    m_descriptionTxt = new QLabel("Hello, world!", this);
    m_descriptionTxt->setTextInteractionFlags(Qt::TextSelectableByMouse);
    m_descriptionTxt->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    for (int var = 0; var < 50; ++var)
    {
        m_descriptionTxt->setText(m_descriptionTxt->text() + QString("Hello\n"));
    }

    m_mainScrollLay->addWidget(m_pictureWidget, 0, Qt::AlignTop);
    m_mainScrollLay->addWidget(m_screenshotsScrollArea, 0, Qt::AlignHCenter);
    m_mainScrollLay->addWidget(m_gameTitleLbl, 0, Qt::AlignHCenter);
    m_mainScrollLay->addWidget(m_descriptionTxt, 1);

    setLayout(m_mainLay);
}


void GamePage::paintEvent(QPaintEvent *event)
{
}

void GamePage::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_pictureWidget->scaleToWidth(size().width());
    m_screenshotsScrollArea->setFixedWidth(size().width());
}
