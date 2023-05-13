
#include "Login_Popup.h"

LoginPopup::LoginPopup(const QPixmap &logo, QWidget *parent)
    : Popup{parent}, m_logoPixmap{logo}
{
    setObjectName("popup");
    m_mainLay = new QVBoxLayout;
    m_mainLay->setContentsMargins(50, 50, 50, 50);
    m_mainLay->setSpacing(18);

    m_logoLbl = new QLabel(this);
    m_logoLbl->setObjectName("logo");
    m_logoLbl->setPixmap(m_logoPixmap);

    m_usernameEdit = new QLineEdit(this);
    m_usernameEdit->setPlaceholderText("Username or email");

    m_passwordEdit = new QLineEdit(this);
    m_passwordEdit->setPlaceholderText("Password");
    m_passwordEdit->setEchoMode(QLineEdit::Password);

    m_signInBtn = new QPushButton("Sign In", this);

    m_mainLay->addWidget(m_logoLbl, 0, Qt::AlignTop | Qt::AlignHCenter);
    m_mainLay->addWidget(new QLabel("Sign In", this), 0, Qt::AlignTop | Qt::AlignLeft);
    m_mainLay->addWidget(m_usernameEdit, 0, Qt::AlignTop);
    m_mainLay->addWidget(m_passwordEdit, 0, Qt::AlignTop);
    m_mainLay->addWidget(m_signInBtn, 0, Qt::AlignTop | Qt::AlignHCenter);
    setLayout(m_mainLay);
}
