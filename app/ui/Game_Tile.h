
#ifndef GAMETILE_H
#define GAMETILE_H

#include <QAbstractButton>
#include <QPainter>
#include <QPainterPath>

#include "network/Web_Downloader.h"


class GameTile : public QAbstractButton
{
    Q_OBJECT
public:
    explicit GameTile(QWidget *parent = nullptr);
    explicit GameTile(const QString &title, int id, const QString &coverFilePath, QWidget *parent = nullptr);
    void setTitle(const QString &title);
    void setCover(QPixmap pixmap);
    QSize sizeHint() const override;
    int id() const;
    void setId(int id);

protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void resizeEvent(QResizeEvent  *event) override;
signals:
    void opened(int id);
private:
    void fitPixmap();

    WebDownloader *m_webDownloader;

    QPixmap m_coverPixmap;
    QPixmap m_coverPixmapResized;
    QSize m_size;

    QSizeF m_coverSize;
    QPointF m_coverPos;

    QSizeF m_titleBgSize;
    QPointF m_titleBgPos;
    QPointF m_titlePos;

    QPointF m_pixmapPos;
    qreal m_padding, m_offset;

    /*  */
    QString m_title;
    int m_id;
    QString m_coverFilePath;

    bool m_isMouseInside;
};

#endif // GAMETILE_H
