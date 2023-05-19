
#ifndef GAMETILE_H
#define GAMETILE_H

#include <QAbstractButton>
#include <QPainter>
#include <QPainterPath>


class GameTile : public QAbstractButton
{
    Q_OBJECT
public:
    explicit GameTile(QWidget *parent = nullptr);
    void setTitle(const QString &title);
    void setCover(QPixmap pixmap);
    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void resizeEvent(QResizeEvent  *event) override;
signals:
private:
    QPixmap m_coverPixmap;

    QSize m_size;

    QSizeF m_coverSize;
    QPointF m_coverPos;

    QSizeF m_titleBgSize;
    QPointF m_titleBgPos;
    QPointF m_titlePos;

    QPointF m_pixmapPos;
    qreal m_padding, m_offset;

    QString m_title;

    bool m_isMouseInside;
};

#endif // GAMETILE_H
