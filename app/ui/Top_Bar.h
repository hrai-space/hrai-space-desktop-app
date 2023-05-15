
#ifndef TOPBAR_H
#define TOPBAR_H


#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>


class TopBar : public QWidget
{
    Q_OBJECT
public:
    explicit TopBar(const QPixmap &logo, QWidget *parent = nullptr);

signals:
    void openLogInPopup();
    void backToLibraryPage();
private:
    QHBoxLayout *m_mainLay;
    QPushButton *m_logoBtn;
    QLineEdit *m_findTxtEdit;
    QPushButton *m_profileBtn;
    QPixmap m_logoPixmap;
    QPixmap m_avatarPixmap;
};

#endif // TOPBAR_H
