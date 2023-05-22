
#include <QStringList>
#include <QDebug>

#include "Network_Manager.h"


NetworkManager::NetworkManager(QObject *parent)
    : QObject(parent), m_networkAccessManager(new QNetworkAccessManager(this))
    , m_user(new User)
{
    m_baseUrl = "https://hrai.space/api/v1/";
    /* Conections */
    connect(m_networkAccessManager, &QNetworkAccessManager::finished,
            this, &NetworkManager::onResponse);
}

NetworkManager::~NetworkManager()
{
    delete m_user;
    foreach (auto game, m_gameLibraryHash)
        delete game;
    m_gameLibraryHash.clear();
    delete m_networkAccessManager;
}

void NetworkManager::requestLogin(const QString &login, const QString &password)
{
    m_requestType = REQUEST_TYPE::LOGIN;
    m_user->setLogin(login);
    m_user->setPassword(password);
    QString url = m_baseUrl + QString("auth/login/%1/%2").arg(login, password);
    qDebug() << "[REQUEST] " << url;
    m_request.setUrl(url);
    m_networkAccessManager->get(m_request);
}

void NetworkManager::requestGameLibrary()
{
    m_requestType = REQUEST_TYPE::GAME_LIB;
    QString url = m_baseUrl + QString("get/followed/%1").arg(m_user->id());
    qDebug() << "[REQUEST] " << url;
    m_request.setUrl(url);
    m_networkAccessManager->get(m_request);
}

void NetworkManager::requestGame(const int gameId)
{
    m_requestType = REQUEST_TYPE::GAME;
    QString url = m_baseUrl + QString("get/game/%1").arg(gameId);
    qDebug() << "[REQUEST] " << url;
    m_request.setUrl(url);
    m_networkAccessManager->get(m_request);
}

void NetworkManager::onResponse(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    QJsonParseError json_error;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data, &json_error);

    switch (m_requestType)
    {
    case LOGIN:
    {
        QJsonObject json_object = json_doc.object();
        if (!json_object.contains("user"))
            break;
        QJsonObject user_object = json_object["user"].toObject();
        m_user->setId(user_object["id"].toInt());
        m_user->setAvatartLink(user_object["avatar"].toString());
        emit responseLogin(m_user);
        break;
    }
    case GAME_LIB:
    {
        foreach (auto game, m_gameLibraryHash)
            delete game;
        m_gameLibraryHash.clear();
        QJsonArray json_array = json_doc.array();
        for (auto item : json_array)
        {
            QJsonObject game_object = item.toObject();
            int id = game_object["game_id"].toInt();
            QString title = game_object["title"].toString();
            QString short_description = game_object["short_description"].toString();
            QString icon_link = game_object["icon"].toString();

            Game *game = new Game(id, title, short_description, icon_link);
            m_gameLibraryHash.insert(id, game);
        }
        emit responseGameLibrary(m_gameLibraryHash);
        break;
    }
    case GAME:
    {
        QJsonObject json_object = json_doc.object();
        if (!json_object.contains("game"))
            break;

        QJsonObject game_object = json_object["game"].toObject();
        int id = game_object["id"].toInt();
        if (!m_gameLibraryHash.contains(id))
            break;

        Game *game = m_gameLibraryHash.value(id);

        QString description = game_object["description"].toString();

        QStringList screenshot_links;
        QJsonArray json_array = game_object["screenshots_a_s_c"].toArray();
        for (auto item : json_array)
        {
            QJsonObject object = item.toObject();
            screenshot_links.append(object["file"].toString());
        }

        QStringList file_links;
        QStringList file_names;
        json_array = game_object["files"].toArray();
        for (auto item : json_array)
        {
            QJsonObject object = item.toObject();
            file_links.append(object["file"].toString());
            file_names.append(object["name"].toString());
        }
        game->setDescription(description);
        game->setScreenshotLinks(screenshot_links);
        game->setFileLinks(file_links);
        game->setFileNames(file_names);
        emit responseGame(game);
        break;
    }
    default:
        break;
    }
    qDebug() << "[RESPONSE]\n" << response_data;
}
