
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
    void setRatio(int width, int height);
    void scaleToWidth(int width);
    void scaleToHeight(int height);
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent  *event) override;
signals:

private:
    void fitPixmap();
    QSize m_size;
    //QSize m_newSize;
    int m_maxHeight;
    qreal m_ratioCoeff;

    QPixmap *m_pixmap;
    QPixmap m_resizedPixmap;
    QPointF m_pixmapPos;

    qreal m_xRadius;
    qreal m_yRadius;
};

#endif // PICTUREWIDGET_H
