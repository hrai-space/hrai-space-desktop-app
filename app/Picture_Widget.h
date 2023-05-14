
#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H


#include <QWidget>


class PictureWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PictureWidget(QWidget *parent = nullptr);
    void setPixmap(QPixmap *pixmap);
    void setCornerRadius(qreal xRadius, qreal yRadius);
    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent  *event) override;
signals:

private:
    void fitPixmap();
    QSize m_size;

    QPixmap *m_pixmap;
    QPixmap m_resizedPixmap;
    QPointF m_pixmapPos;

    qreal m_xRadius;
    qreal m_yRadius;
};

#endif // PICTUREWIDGET_H
