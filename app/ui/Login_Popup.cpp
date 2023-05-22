
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
    m_usernameEdit->setPlaceholderText("Ім'я користувача чи пошта");
    m_usernameEdit->setText("severus");

    m_passwordEdit = new QLineEdit(this);
    m_passwordEdit->setPlaceholderText("Пароль");
    m_passwordEdit->setEchoMode(QLineEdit::Password);
    m_passwordEdit->setText("x01abs10js");

    m_signInBtn = new QPushButton("Увійти", this);

    m_mainLay->addWidget(m_logoLbl, 0, Qt::AlignTop | Qt::AlignHCenter);
    m_mainLay->addWidget(new QLabel("Вхід", this), 0, Qt::AlignTop | Qt::AlignLeft);
    m_mainLay->addWidget(m_usernameEdit, 0, Qt::AlignTop);
    m_mainLay->addWidget(m_passwordEdit, 0, Qt::AlignTop);
    m_mainLay->addWidget(m_signInBtn, 0, Qt::AlignTop | Qt::AlignHCenter);
    setLayout(m_mainLay);
    /* Conections */
    connect(m_signInBtn, &QPushButton::released, this,
            [=]()
            {
                QString username = m_usernameEdit->text();
                QString password = m_passwordEdit->text();
                if (username.isEmpty() || password.isEmpty())
                    return;
                emit requestLogin(username, password);
            });
}
