
#include <QDebug>
#include <QPainter>
#include <QStringList>

#include "Game_Page.h"

GamePage::GamePage(const Game *game, QWidget *parent)
    : QWidget{parent}, m_game{game}
{
    m_mainLay = new QVBoxLayout;
    m_mainLay->setContentsMargins(0, 0, 0, 0);
    m_mainLay->setSpacing(0);

    m_mainScrollLay = new QVBoxLayout;
    //m_mainScrollLay->setSizeConstraint(QLayout::SetMaximumSize);
    m_mainScrollLay->setContentsMargins(0, 0, 0, 20);
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
    m_screenshotsHBoxLay->setContentsMargins(20, 0, 20, 0);
    //m_screenshotsHBoxLay->setSpacing(10);
    m_screenshotsScrollWidget = new QWidget(this);
    m_screenshotsScrollArea = new QScrollArea(this);
    m_screenshotsScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_screenshotsScrollArea->setWidgetResizable(true);
    m_screenshotsScrollArea->setWidget(m_screenshotsScrollWidget);
    m_screenshotsScrollWidget->setLayout(m_screenshotsHBoxLay);
    m_screenshotsScrollArea->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_screenshotsScrollArea->setFixedHeight(200);

    /* Current screenshot */
    m_pictureWidget = new PictureWidget(game->id(), this);
    m_pictureWidget->setCornerRadius(20.0, 20.0);
    m_pictureWidget->loadPixmapFromWeb(m_game->iconLink());

    /* Screenshots */
    QStringList screenshot_links = m_game->screenshotLinks();
    int screenshot_id = 0;
    for (const QString &link : screenshot_links)
    {
        PictureWidget *picture_widget = new PictureWidget(screenshot_id, this);
        picture_widget->loadPixmapFromWeb(link);
        picture_widget->setCornerRadius(8.0, 8.0);
        picture_widget->scaleToHeight(170);
        connect(picture_widget, &PictureWidget::clickedId, this, &GamePage::screenshotChanged);
        m_pictureWidgets.append(picture_widget);
        m_screenshotsHBoxLay->addWidget(picture_widget);
        screenshot_id++;
    }


    /* Title */
    m_gameTitleLbl = new QLabel(m_game->title(), this);
    m_gameTitleLbl->setObjectName("pgtitle");
    m_gameTitleLbl->setTextInteractionFlags(Qt::TextSelectableByMouse);
    //m_gameTitleLbl->setTextFormat(Qt::PlainText);

    /* Description */
    m_descriptionTxt = new QLabel(m_game->description(), this);
    m_descriptionTxt->setObjectName("descr");
    m_descriptionTxt->setTextInteractionFlags(Qt::TextSelectableByMouse);
    m_descriptionTxt->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_descriptionTxt->setWordWrap(true);
    m_descriptionTxt->setStyleSheet("QLabel {padding: 20px;}");


    /* Main layout */
    m_mainScrollLay->addWidget(m_pictureWidget, 0, Qt::AlignTop);
    m_mainScrollLay->addWidget(m_screenshotsScrollArea, 0, Qt::AlignHCenter);
    m_mainScrollLay->addWidget(m_gameTitleLbl, 0, Qt::AlignHCenter);
    m_mainScrollLay->addWidget(m_descriptionTxt, 1);

    /* Attached files */
    QStringList file_names = m_game->fileNames();
    QStringList file_links = m_game->fileLinks();
    for (int i = 0; i < file_links.size(); ++i)
    {
        QPushButton *link_btn = new QPushButton(file_names[i], this);
        link_btn->setObjectName("lnkbtn");
        connect(link_btn, &QPushButton::clicked, this, &GamePage::downloadAttachedFile);
        m_linkButtons.append(link_btn);
        m_mainScrollLay->addWidget(link_btn, 0, Qt::AlignLeft);
    }

    setLayout(m_mainLay);
}

void GamePage::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_pictureWidget->scaleToWidth(size().width());
    m_screenshotsScrollArea->setFixedWidth(size().width());
}

void GamePage::screenshotChanged(int id)
{
    m_pictureWidget->setPixmap(m_pictureWidgets[id]->pixmap());
}

void GamePage::downloadAttachedFile()
{
    QPushButton* clicked_link_button = qobject_cast<QPushButton*>(sender());
    int link_n = m_linkButtons.indexOf(clicked_link_button);
    m_fileDialog.setFileMode(QFileDialog::Directory);
    if (m_fileDialog.exec())
    {
        m_downloadDir = m_fileDialog.directory();
    }
    qDebug() << "[INFO] Dir: " << m_downloadDir;
    qDebug() << "[INFO] Link: " << m_game->fileLinks()[link_n];
}
