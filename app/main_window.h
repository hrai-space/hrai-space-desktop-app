#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QStackedLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>

#include "Top_Bar.h"
#include "Library_Page.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

private:
    QVBoxLayout *m_mainLay;

    // Top bar
    TopBar *m_topBarWidget;

    // Body area
    LibraryPage *m_libraryPage;
    QStackedLayout *m_bodyStackedLay;
    QGridLayout *m_bodyGridLay;
    QFrame *m_bodyFrame;

};
#endif // MAINWINDOW_H
