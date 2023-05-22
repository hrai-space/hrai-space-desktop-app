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
#include "network/Network_Manager.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
    void resizeEvent(QResizeEvent  *event) override;
private slots:
    void openLogInPopup();
    void responseLogin(const User *user);
    void backToLibraryPage();
    void openGamePage(const Game *game);
private:
    NetworkManager *m_networkManager;

    QVBoxLayout *m_mainLay;

    QPixmap m_logoPixmap;
    QPixmap m_logoFullPixmap;

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
