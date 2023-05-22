
#include "User.h"


User::User()
{
    m_id = 0;
}

User::User(int id, QString login, QString password)
{
    m_id = id;
    m_login = login;
    m_password = password;
}

void User::setId(int id)
{
    m_id = id;
}

void User::setLogin(const QString &login)
{
    m_login = login;
}

void User::setPassword(const QString &password)
{
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

QString User::avatartLink() const
{
    return m_avatartLink;
}

void User::setAvatartLink(const QString &avatartLink)
{
    m_avatartLink = avatartLink;
}

