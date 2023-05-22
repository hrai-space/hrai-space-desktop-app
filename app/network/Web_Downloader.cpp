
#include "Web_Downloader.h"

WebDownloader::WebDownloader(QObject *parent)
    : QObject{parent}, m_networkAccessManager{new QNetworkAccessManager}
{
    /* Conections */
    QObject::connect(m_networkAccessManager, &QNetworkAccessManager::finished,
                     this, &WebDownloader::onResponse);
}

void WebDownloader::downloadFromWeb(const QString &webUrl)
{
    m_request.setUrl(webUrl);
    m_networkAccessManager->get(m_request);
}

void WebDownloader::onResponse(QNetworkReply *reply)
{
    m_data = reply->readAll();
    emit onGetData(m_data);
}

