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
#include "Login_Popup.h"
#include "Game_Page.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void openLogInPopup();
protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
    void resizeEvent(QResizeEvent  *event) override;
private:
    QVBoxLayout *m_mainLay;

    QPixmap m_logoPixmap;

    // Top bar
    TopBar *m_topBarWidget;

    // Body area
    QStackedLayout *m_bodyStackedLay;
    QGridLayout *m_bodyGridLay;
    QFrame *m_bodyFrame;

    // Log In popup
    LoginPopup *m_logInPopup;

    // Library page
    LibraryPage *m_libraryPage;

    // Game page
    GamePage *m_gamePage;


};
#endif // MAINWINDOW_H
