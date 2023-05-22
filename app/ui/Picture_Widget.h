
#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H


#include <QAbstractButton>

#include "network/Web_Downloader.h"


class PictureWidget : public QAbstractButton
{
    Q_OBJECT
public:
    explicit PictureWidget(int id = 0, QWidget *parent = nullptr);
    void setPixmap(QPixmap pixmap);
    void setCornerRadius(qreal xRadius, qreal yRadius);
    void setRatio(int width, int height);
    void scaleToWidth(int width);
    void scaleToHeight(int height);
    void loadPixmapFromWeb(const QString &url);
    QSize sizeHint() const override;
    QPixmap pixmap();
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent  *event) override;
signals:
    void clickedId(int id);
private:
    WebDownloader *m_webDownloader;

    void fitPixmap();
    QSize m_size;
    int m_maxHeight;
    qreal m_ratioCoeff;

    QPixmap m_pixmap;
    QPixmap m_resizedPixmap;
    QPointF m_pixmapPos;

    qreal m_xRadius;
    qreal m_yRadius;
};

#endif // PICTUREWIDGET_H
