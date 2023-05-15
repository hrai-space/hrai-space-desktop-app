
#ifndef USER_H
#define USER_H

#include <QString>


class User
{
public:
    User(int id, QString login, QString password);
    int id() const;
    QString login() const;
    QString password() const;

private:
    int m_id;
    QString m_login;
    QString m_password;
};

#endif // USER_H
