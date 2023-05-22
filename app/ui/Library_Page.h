
#ifndef LIBRARYPAGE_H
#define LIBRARYPAGE_H


#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QHash>


#include "data/Game.h"

class LibraryPage : public QWidget
{
    Q_OBJECT
public:
    explicit LibraryPage(QWidget *parent = nullptr);

signals:
    void requestGame(int gameId);

public slots:
    void fillGameLibrary(const QHash<int, Game*> &gameLibrary);

private:
    void clearGameLibrary();

    QVBoxLayout *m_mainLay;
    QGridLayout *m_gridLay;
    QScrollArea *m_scrollArea;
    QWidget *m_scrollWidget;
    QLabel *m_pageTitleLbl;
};

#endif // LIBRARYPAGE_H
