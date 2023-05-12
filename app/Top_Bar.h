
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
    explicit TopBar(QWidget *parent = nullptr);

signals:
    void openLogInPopup();
private:
    QHBoxLayout *m_mainLay;
    QLabel *m_logoLbl;
    QLineEdit *m_findTxtEdit;
    QPushButton *m_profileBtn;
    QPixmap m_logoPixmap;
    QPixmap m_avatarPixmap;
};

#endif // TOPBAR_H
