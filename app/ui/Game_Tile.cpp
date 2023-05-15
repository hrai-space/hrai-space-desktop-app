
#include <QDebug>
#include <QResizeEvent>

#include "Game_Tile.h"

GameTile::GameTile(QWidget *parent)
    : QAbstractButton{parent}, m_isMouseInside{false}, m_padding{4.0}, m_offset{3.0}
{
    //m_coverPixmap = QPixmap("../app/resources/game-cover.png");
    m_coverPixmap = QPixmap("../app/resources/pubg.jpg");
    qDebug() << "Size = " << size() << " [GameTile::GameTile]";
}

void GameTile::setTitle(const QString &title)
{

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
    painter.drawPixmap(m_pixmapPos, m_coverPixmap);
    painter.setClipping(false);

    // Title text
    QFont font = painter.font();
    font.setFamily("Public Sans Thin Regular");
    //font.setWeight(60);
    font.setPointSize(12);
    painter.setFont(font);
    painter.setPen(pen_title);
    painter.drawText(m_titlePos, "Dark Story");
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

    QSize pixmap_size = m_coverPixmap.size();
    if (pixmap_size.width() >= pixmap_size.height())
    {
        m_coverPixmap = m_coverPixmap.scaledToHeight(m_coverSize.height(), Qt::SmoothTransformation);
        pixmap_size = m_coverPixmap.size();
        m_pixmapPos = QPointF((m_coverSize.width() - pixmap_size.width()) / 2, m_padding);
    }
    else if (pixmap_size.width() < pixmap_size.height())
    {
        m_coverPixmap = m_coverPixmap.scaledToWidth(m_coverSize.width(), Qt::SmoothTransformation);
        pixmap_size = m_coverPixmap.size();
        m_pixmapPos = QPointF(m_padding, (m_coverSize.height() - pixmap_size.height()) / 2);
    }
}

