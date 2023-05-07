
#ifndef LIBRARYPAGE_H
#define LIBRARYPAGE_H


#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>

#include "Game_Tile.h"

class LibraryPage : public QWidget
{
    Q_OBJECT
public:
    explicit LibraryPage(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout *m_mainLay;
    QGridLayout *m_gridLay;
    QScrollArea *m_scrollArea;
    QWidget *m_scrollWidget;
};

#endif // LIBRARYPAGE_H
