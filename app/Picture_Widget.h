
#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H


#include <QWidget>


class PictureWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PictureWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent  *event) override;
signals:

private:
    void fitPixmap(QPixmap &pixmap);

};

#endif // PICTUREWIDGET_H
