
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
    m_mainScrollLay->setContentsMargins(0, 0, 0, 0);
    //m_mainScrollLay->setSpacing(0);
    //m_mainScrollLay->setSizeConstraint(QLayout::SetMinimumSize);
    m_centralWidget = new QWidget(this);
    m_centralWidget->setObjectName("gamepg");
    //m_centralWidget->setStyleSheet("background: transparent;");
    m_mainScrollArea = new QScrollArea(this);
    //m_mainScrollArea->setStyleSheet("background: transparent;");
    m_mainScrollArea->setWidgetResizable(true);
    //m_mainScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_mainScrollArea->setWidget(m_centralWidget);
    m_centralWidget->setLayout(m_mainScrollLay);

    m_mainLay->addWidget(m_mainScrollArea);


    /* Screenshots area */
    m_screenshotsGridLay = new QGridLayout;
    //m_screenshotsGridLay->setContentsMargins(0, 0, 0, 0);
    //m_screenshotsGridLay->setSpacing(0);
    m_screenshotsScrollWidget = new QWidget(this);
    m_screenshotsScrollArea = new QScrollArea(this);
    //m_screenshotsScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //m_screenshotsScrollArea->setWidgetResizable(true);
    m_screenshotsScrollArea->setWidget(m_screenshotsScrollWidget);
    m_screenshotsScrollWidget->setLayout(m_screenshotsGridLay);
    //m_screenshotsGridLay->setSizeConstraint(QLayout::SetMaximumSize);


    m_screenshotPixmap = QPixmap("../app/resources/pubg.jpg");
    //QPixmap scaled_screenshot = m_screenshotPixmap.scaledToWidth(size().width(), Qt::SmoothTransformation);
    m_screenshotLbl = new QLabel(this);
    //m_screenshotLbl->setAlignment(Qt::AlignHCenter);
    m_screenshotLbl->setPixmap(m_screenshotPixmap);
    m_screenshotLbl->setStyleSheet("background: red; border-radius: 50px;");

    m_gameTitleLbl = new QLabel("Dark Story", this);
    m_gameTitleLbl->setObjectName("pgtitle");

    m_descriptionTxt = new QLabel("Hello, world!", this);
//    m_descriptionTxt->setTextInteractionFlags(Qt::TextSelectableByMouse);
//    m_descriptionTxt->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
//    for (int var = 0; var < 50; ++var)
//    {
//        m_descriptionTxt->setText(m_descriptionTxt->text() + QString("Hello\n"));
//    }


    m_mainScrollLay->addWidget(m_screenshotLbl, 0, Qt::AlignTop);
    m_mainScrollLay->addWidget(m_screenshotsScrollArea);
    m_mainScrollLay->addWidget(m_gameTitleLbl, 0, Qt::AlignLeft | Qt::AlignTop);
    m_mainScrollLay->addWidget(m_descriptionTxt, 1);

    for (int var = 0; var < 100; ++var)
    {
        m_descriptionTxt = new QLabel(QString("Label %1").arg(var), this);
        m_mainScrollLay->addWidget(m_descriptionTxt, 0);
    }

    setLayout(m_mainLay);
}


void GamePage::paintEvent(QPaintEvent *event)
{
//    m_size = size();
//    QPainter painter(this);
//    painter.setRenderHints(QPainter::Antialiasing);
//    painter.setPen(Qt::NoPen);
//    QPen pen_title(QColor(92, 147, 233), 1, Qt::SolidLine);
//    QBrush brush_hover_bg(QColor(22, 26, 30), Qt::SolidPattern);
//    QBrush brush_cover_bg(QColor(18, 20, 22), Qt::SolidPattern);
//    QBrush brush_title_bg(QColor(0, 255, 0), Qt::SolidPattern);

//    // Background
//    painter.setBrush(brush_title_bg);
//    painter.drawRoundedRect(0, 0, m_size.width(), m_size.height(), 20.0, 20.0);

    //painter.setClipPath(path);
    //painter.drawPixmap(m_pixmapPos, m_coverPixmap);
    //painter.setClipping(false);

    //QWidget::paintEvent(event);
}

void GamePage::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}
