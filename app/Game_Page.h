
#ifndef GAMEPAGE_H
#define GAMEPAGE_H


#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>

class GamePage : public QWidget
{
    Q_OBJECT
public:
    explicit GamePage(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout *m_mainLay;

    QVBoxLayout *m_mainScrollLay;
    QScrollArea *m_mainScrollArea;
    QWidget *m_centralWidget;

    QGridLayout *m_screenshotsGridLay;
    QScrollArea *m_screenshotsScrollArea;
    QWidget *m_screenshotsScrollWidget;

    QPixmap m_screenshotPixmap;
    QLabel *m_screenshotLbl;
    QLabel *m_gameTitleLbl;
    QLabel *m_descriptionTxt;
};

#endif // GAMEPAGE_H
