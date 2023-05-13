
#ifndef POPUP_H
#define POPUP_H


#include <QWidget>


class Popup : public QWidget
{
    Q_OBJECT
public:
    explicit Popup(QWidget *parent = nullptr);
    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent  *event) override;
signals:
private:
    QSize m_size;
    QSize m_pos;
    qreal m_borderWidth;

    bool m_isMouseInside;
};

#endif // POPUP_H
