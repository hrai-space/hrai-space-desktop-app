
#include <QDebug>
#include <QResizeEvent>

#include "Game_Tile.h"

GameTile::GameTile(QWidget *parent)
    : QAbstractButton{parent}, m_webDownloader{new WebDownloader}
    , m_isMouseInside{false}, m_padding{4.0}, m_offset{3.0}
{
    qDebug() << "Size = " << size() << " [GameTile::GameTile]";
}

GameTile::GameTile(const QString &title, int id, const QString &coverFilePath, QWidget *parent)
    : QAbstractButton{parent}, m_webDownloader{new WebDownloader}
    , m_isMouseInside{false}, m_padding{4.0}, m_offset{3.0}
{
    m_title = title;
    m_id = id;
    m_coverFilePath = coverFilePath;

    m_webDownloader->downloadFromWeb(coverFilePath);

    connect(m_webDownloader, &WebDownloader::onGetData, this, [=](QByteArray data)
            {
                m_coverPixmap.loadFromData(data);
                fitPixmap();
                repaint();
            });
    connect(this, &GameTile::clicked, this, [=]()
            {
                emit opened(id);
            });
}

void GameTile::setTitle(const QString &title)
{
    m_title = title;
}

void GameTile::setCover(QPixmap pixmap)
{

}

QSize GameTile::sizeHint() const
{
    return QSize(368, 350);
}

void GameTile::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    QPen pen_title(QColor(92, 147, 233), 1, Qt::SolidLine);
    QBrush brush_hover_bg(QColor(22, 26, 30), Qt::SolidPattern);
    QBrush brush_cover_bg(QColor(18, 20, 22), Qt::SolidPattern);
    QBrush brush_title_bg(QColor(22, 26, 30), Qt::SolidPattern);

    // Background on hover
    if (m_isMouseInside)
    {
        painter.setBrush(brush_hover_bg);
        painter.drawRoundedRect(0, 0, m_size.width(), m_size.height(), 20.0, 20.0);
    }

    // Title background
    painter.setBrush(brush_title_bg);
    painter.drawRoundedRect(m_titleBgPos.x(), m_titleBgPos.y(),
                            m_titleBgSize.width(), m_titleBgSize.height(),
                            20.0, 20.0);

    // Cover background
    painter.setBrush(brush_cover_bg);
    painter.drawRoundedRect(m_coverPos.x(), m_coverPos.y(),
                            m_coverSize.width(), m_coverSize.height(),
                            20.0, 20.0);

    // Cover image
    QPainterPath path = QPainterPath();
    path.addRoundedRect(m_coverPos.x(), m_coverPos.y(),
                        m_coverSize.width(), m_coverSize.height(),
                        20.0, 20.0);
    painter.setClipPath(path);
    painter.drawPixmap(m_pixmapPos+m_coverPos, m_coverPixmapResized);
    painter.setClipping(false);

    // Title text
    QFont font = painter.font();
    //font.setFamily("Public Sans Thin Regular");
    font.setWeight(60);
    font.setPointSize(12);
    painter.setFont(font);
    painter.setPen(pen_title);
    painter.drawText(m_titlePos, m_title);
}

void GameTile::enterEvent(QEvent *event)
{
    m_isMouseInside = true;
    QAbstractButton::enterEvent(event);
}

void GameTile::leaveEvent(QEvent *event)
{
    m_isMouseInside = false;
    QAbstractButton::enterEvent(event);
}

void GameTile::resizeEvent(QResizeEvent *event)
{
    QAbstractButton::resizeEvent(event);
    m_size = size();
    m_coverSize = QSizeF(m_size.width() - (m_padding * 2 + m_offset), m_size.height() * 0.79);
    m_coverPos = QPointF(m_padding + m_offset, m_padding);
    m_titleBgSize = QSizeF(m_coverSize.width(), m_size.height() * 0.3);
    m_titleBgPos = QPointF(m_padding, m_size.height() - m_titleBgSize.height() - m_padding);

    m_titlePos = QPointF(m_coverPos.x() + 4 * m_padding, m_titleBgPos.y() + m_titleBgSize.height() * 0.65);
    fitPixmap();
}

void GameTile::fitPixmap()
{
    QSize pixmap_size = m_coverPixmap.size();
    if (pixmap_size.isEmpty())
        return;

    qreal pixmap_ration = (qreal) pixmap_size.width() / pixmap_size.height();
    qreal widget_ration = (qreal) m_coverSize.width() / m_coverSize.height();

    if (widget_ration > pixmap_ration)
    {
        m_coverPixmapResized = m_coverPixmap.scaledToWidth(m_coverSize.width(), Qt::SmoothTransformation);
        pixmap_size = m_coverPixmapResized.size();
        m_pixmapPos = QPointF(0, (m_coverSize.height() - pixmap_size.height()) / 2);
        if (m_pixmapPos.y() > 0)
            m_pixmapPos.setY(0);
    }
    else
    {
        m_coverPixmapResized = m_coverPixmap.scaledToHeight(m_coverSize.height(), Qt::SmoothTransformation);
        pixmap_size = m_coverPixmapResized.size();
        m_pixmapPos = QPointF((m_coverSize.width() - pixmap_size.width()) / 2, 0);
        if (m_pixmapPos.x() > 0)
            m_pixmapPos.setX(0);
    }
}

int GameTile::id() const
{
    return m_id;
}

void GameTile::setId(int id)
{
    m_id = id;
}

