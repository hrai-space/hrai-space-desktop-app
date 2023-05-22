
#ifndef USER_H
#define USER_H

#include <QString>


class User
{
public:
    User();
    User(int id, QString login, QString password);
    void setId(int id);
    void setLogin(const QString &login);
    void setPassword(const QString &password);

    int id() const;
    QString login() const;
    QString password() const;

    QString avatartLink() const;
    void setAvatartLink(const QString &newAvatartLink);

private:
    int m_id;
    QString m_login;
    QString m_password;
    QString m_avatartLink;
};

#endif // USER_H
