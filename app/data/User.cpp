
#include "User.h"


User::User(int id, QString login, QString password)
{
    m_id = id;
    m_login = login;
    m_password = password;
}

int User::id() const
{
    return m_id;
}

QString User::login() const
{
    return m_login;
}

QString User::password() const
{
    return m_password;
}

