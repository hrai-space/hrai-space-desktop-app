
#ifndef LOGINPOPUP_H
#define LOGINPOPUP_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

#include "Popup.h"


class LoginPopup : public Popup
{
    Q_OBJECT
public:
    explicit LoginPopup(const QPixmap &logo, QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout *m_mainLay;
    QPixmap m_logoPixmap;
    QLabel *m_logoLbl;
    QLineEdit *m_usernameEdit;
    QLineEdit *m_passwordEdit;
    QPushButton *m_signInBtn;
};

#endif // LOGINPOPUP_H
