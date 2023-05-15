
#ifndef GAMEPAGE_H
#define GAMEPAGE_H


#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QScrollArea>

#include "Picture_Widget.h"

class GamePage : public QWidget
{
    Q_OBJECT
public:
    explicit GamePage(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent  *event) override;
signals:

private:
    QSize m_size;

    QVBoxLayout *m_mainLay;

    QVBoxLayout *m_mainScrollLay;
    QScrollArea *m_mainScrollArea;
    QWidget *m_centralWidget;

    QHBoxLayout *m_screenshotsHBoxLay;
    QScrollArea *m_screenshotsScrollArea;
    QWidget *m_screenshotsScrollWidget;

    QPixmap m_screenshotPixmap;
    QLabel *m_screenshotLbl;
    QLabel *m_gameTitleLbl;
    QLabel *m_descriptionTxt;

    PictureWidget *m_pictureWidget;
};

#endif // GAMEPAGE_H
