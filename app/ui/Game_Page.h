
#ifndef GAMEPAGE_H
#define GAMEPAGE_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QVector>
#include <QFileDialog>

#include "Picture_Widget.h"
#include "data/Game.h"

class GamePage : public QWidget
{
    Q_OBJECT
public:
    explicit GamePage(const Game *game, QWidget *parent = nullptr);
protected:
    void resizeEvent(QResizeEvent  *event) override;
signals:
private slots:
    void screenshotChanged(int id);
    void downloadAttachedFile();
private:
    QSize m_size;

    QVBoxLayout *m_mainLay;

    QVBoxLayout *m_mainScrollLay;
    QScrollArea *m_mainScrollArea;
    QWidget *m_centralWidget;

    QHBoxLayout *m_screenshotsHBoxLay;
    QScrollArea *m_screenshotsScrollArea;
    QWidget *m_screenshotsScrollWidget;

    QLabel *m_screenshotLbl;
    QLabel *m_gameTitleLbl;
    QLabel *m_descriptionTxt;

    PictureWidget *m_pictureWidget;
    QVector<PictureWidget*> m_pictureWidgets;

    QVector<QPushButton*> m_linkButtons;

    const Game *m_game;

    QFileDialog m_fileDialog;
    QDir m_downloadDir;
};

#endif // GAMEPAGE_H
