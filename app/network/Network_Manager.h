
#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QHash>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "data/User.h"
#include "data/Game.h"

enum REQUEST_TYPE { LOGIN, GAME_LIB, GAME };

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    NetworkManager(QObject *parent = nullptr);
    ~NetworkManager();
    void requestLogin(const QString &login, const QString &password);
    void requestGameLibrary();
    void requestGame(const int gameId);
signals:
    void responseLogin(const User *user);
    void responseGameLibrary(const QHash<int, Game*> &gameLibrary);
    void responseGame(const Game *game);
private slots:
    void onResponse(QNetworkReply *reply);
private:
    QNetworkAccessManager *m_networkAccessManager;
    QNetworkRequest m_request;
    QString m_baseUrl;

    REQUEST_TYPE m_requestType;

    User *m_user;
    QHash<int, Game*> m_gameLibraryHash;
};

#endif // NETWORKMANAGER_H
