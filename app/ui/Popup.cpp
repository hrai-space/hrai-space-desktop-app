
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

#include "Popup.h"

Popup::Popup(QWidget *parent)
    : QWidget{parent}, m_borderWidth{2.0}, m_isMouseInside{false}
{
}

QSize Popup::sizeHint() const
{
    return QSize(600, 600);
}

void Popup::paintEvent(QPaintEvent *event)
{
    m_size = size();
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    //QPen pen_border(QColor(33, 74, 216), 3, Qt::SolidLine);
    QPen pen_border(QColor(33, 74, 216), m_borderWidth);
    QBrush brush_bg(QColor(22, 26, 30), Qt::SolidPattern);
    painter.setPen(pen_border);
    painter.setBrush(brush_bg);
    painter.drawRoundedRect(m_borderWidth, m_borderWidth,
                            m_size.width()-2*m_borderWidth, m_size.height()-2*m_borderWidth,
                            20.0, 20.0);
}

void Popup::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

