
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

#include "Picture_Widget.h"

PictureWidget::PictureWidget(QWidget *parent)
    : QWidget{parent}, m_xRadius{0}, m_yRadius{0}
{

}

void PictureWidget::setPixmap(QPixmap *pixmap)
{
    m_pixmap = pixmap;
    fitPixmap();
}

void PictureWidget::setCornerRadius(qreal xRadius, qreal yRadius)
{
    m_xRadius = xRadius;
    m_yRadius = yRadius;
}

QSize PictureWidget::sizeHint() const
{
    if (m_pixmap != nullptr)
        return m_pixmap->size();
    return QSize(500, 500);
}

void PictureWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    QPainterPath path = QPainterPath();
    path.addRoundedRect(0, 0, m_size.width(), m_size.height(), 20.0, 20.0);
    painter.setClipPath(path);
    painter.drawPixmap(m_pixmapPos, m_resizedPixmap);
}

void PictureWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_size = size();
    fitPixmap();
}

void PictureWidget::fitPixmap()
{
    QSize pixmap_size = m_pixmap->size();
    if (pixmap_size.width() <= pixmap_size.height())
    {
        m_resizedPixmap = m_pixmap->scaledToHeight(m_size.height(), Qt::SmoothTransformation);
        pixmap_size = m_resizedPixmap.size();
        m_pixmapPos = QPointF((m_size.width() - pixmap_size.width()) / 2, 0);
        if (m_pixmapPos.x() > 0)
            m_pixmapPos.setX(0);
    }
    else if (pixmap_size.width() > pixmap_size.height())
    {
        m_resizedPixmap = m_pixmap->scaledToWidth(m_size.width(), Qt::SmoothTransformation);
        pixmap_size = m_resizedPixmap.size();
        m_pixmapPos = QPointF(0, (m_size.height() - pixmap_size.height()) / 2);
        if (m_pixmapPos.y() > 0)
            m_pixmapPos.setY(0);
        //qDebug() << m_pixmapPos << " >";
    }
}

