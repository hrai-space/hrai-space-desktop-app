
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

#include "Picture_Widget.h"

PictureWidget::PictureWidget(int id, QWidget *parent)
    : QAbstractButton{parent}, m_webDownloader{new WebDownloader}
    , m_xRadius{0}
    , m_yRadius{0}
    , m_ratioCoeff{0.5625}
{
    m_maxHeight = 669;
    connect(this, &PictureWidget::clicked, this, [=]()
            {
                emit clickedId(id);
            });
}

PictureWidget::~PictureWidget()
{
    delete m_webDownloader;
}

void PictureWidget::setPixmap(QPixmap pixmap)
{
    m_pixmap = pixmap;
    fitPixmap();
    repaint();
}

void PictureWidget::setCornerRadius(qreal xRadius, qreal yRadius)
{
    m_xRadius = xRadius;
    m_yRadius = yRadius;
}

QSize PictureWidget::sizeHint() const
{
    if (!m_pixmap.isNull())
        return m_pixmap.size();
    return QSize(500, 500);
}

void PictureWidget::setRatio(int width, int height)
{
    m_ratioCoeff = (qreal) height / width;
}

void PictureWidget::scaleToWidth(int width)
{
    m_size.setWidth(width);
    m_size.setHeight(m_ratioCoeff * width);
    setFixedSize(m_size);
}

void PictureWidget::scaleToHeight(int height)
{
    m_size.setWidth(height / m_ratioCoeff);
    m_size.setHeight(height);
    setFixedSize(m_size);
}

void PictureWidget::loadPixmapFromWeb(const QString &url)
{
    m_webDownloader->downloadFromWeb(url);
    connect(m_webDownloader, &WebDownloader::onGetData, this, [=](QByteArray data)
            {
                m_pixmap.loadFromData(data);
                fitPixmap();
                repaint();
            });
}

QPixmap PictureWidget::pixmap()
{
    return m_pixmap;
}

void PictureWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    QPainterPath path = QPainterPath();
    path.addRoundedRect(0, 0,
                        m_size.width(),
                        m_size.height(),
                        m_xRadius, m_yRadius);
    painter.setClipPath(path);
    painter.drawPixmap(m_pixmapPos, m_resizedPixmap);
    //painter.setClipping(false);
}

void PictureWidget::resizeEvent(QResizeEvent *event)
{
    QAbstractButton::resizeEvent(event);
    fitPixmap();
}

void PictureWidget::fitPixmap()
{
    QSize pixmap_size = m_pixmap.size();
    if (pixmap_size.isEmpty())
        return;

    qreal pixmap_ration = (qreal) pixmap_size.width() / pixmap_size.height();
    qreal widget_ration = (qreal) m_size.width() / m_size.height();

    if (widget_ration > pixmap_ration)
    {
        m_resizedPixmap = m_pixmap.scaledToWidth(m_size.width(), Qt::SmoothTransformation);
        pixmap_size = m_resizedPixmap.size();
        m_pixmapPos = QPointF(0, (m_size.height() - pixmap_size.height()) / 2);
        if (m_pixmapPos.y() > 0)
            m_pixmapPos.setY(0);
    }
    else
    {
        m_resizedPixmap = m_pixmap.scaledToHeight(m_size.height(), Qt::SmoothTransformation);
        pixmap_size = m_resizedPixmap.size();
        m_pixmapPos = QPointF((m_size.width() - pixmap_size.width()) / 2, 0);
        if (m_pixmapPos.x() > 0)
            m_pixmapPos.setX(0);
    }
}

