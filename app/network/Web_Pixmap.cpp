
#include "Web_Pixmap.h"

WebPixmap::WebPixmap()
    : QPixmap(), QObject(), m_networkAccessManager(new QNetworkAccessManager)
{
    /* Conections */
    QObject::connect(m_networkAccessManager, &QNetworkAccessManager::finished,
            this, &WebPixmap::onGetPixmapData);
}

void WebPixmap::loadFromWeb(const QString &webUrl)
{
    m_request.setUrl(webUrl);
    m_networkAccessManager->get(m_request);
}

void WebPixmap::onGetPixmapData(QNetworkReply *reply)
{
    QByteArray pixmapData = reply->readAll();
    loadFromData(pixmapData.data());
}

