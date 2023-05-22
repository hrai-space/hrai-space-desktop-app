
#include <QFile>
#include <QDir>

#include "Web_Downloader.h"

WebDownloader::WebDownloader(QObject *parent)
    : QObject{parent}, m_networkAccessManager{new QNetworkAccessManager}
    , m_downloadType{}
{
    /* Conections */
    QObject::connect(m_networkAccessManager, &QNetworkAccessManager::finished,
                     this, &WebDownloader::onResponse);
}

WebDownloader::~WebDownloader()
{
    delete m_networkAccessManager;
}

void WebDownloader::downloadFromWeb(const QString &url)
{
    m_downloadType = DOWNLOAD_TYPE::TO_DATA;
    m_request.setUrl(url);
    m_networkAccessManager->get(m_request);
}

void WebDownloader::downloadFromWebToFile(const QString &url, const QString &dir, const QString &fileName)
{
    m_downloadType = DOWNLOAD_TYPE::TO_FILE;
    m_fileDir = dir;
    m_fileName = fileName;
    m_request.setUrl(url);
    m_networkAccessManager->get(m_request);
}

void WebDownloader::onResponse(QNetworkReply *reply)
{
    m_data = reply->readAll();
    switch (m_downloadType)
    {
    case TO_DATA:
    {
        emit onGetData(m_data);
        break;
    }
    case TO_FILE:
    {
        QDir().mkdir("temp");
        QString filename = QString("%1/%2").arg(m_fileDir, m_fileName);
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly))
            return;
        file.write(m_data);
        file.close();
        emit onFileWritten(filename);
        break;
    }
    default:
        break;
    }
    m_data.clear();
}

