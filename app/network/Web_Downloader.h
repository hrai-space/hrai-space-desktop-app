
#ifndef WEBDOWNLOADER_H
#define WEBDOWNLOADER_H


#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>

enum DOWNLOAD_TYPE { TO_DATA, TO_FILE };

class WebDownloader : public QObject
{
    Q_OBJECT
public:
    explicit WebDownloader(QObject *parent = nullptr);
    void downloadFromWeb(const QString &url);
    void downloadFromWebToFile(const QString &url, const QString &dir, const QString &fileName);
signals:
    void onGetData(QByteArray data);
    void onFileWritten(const QString& filePath);
private slots:
    void onResponse(QNetworkReply *reply);
private:
    DOWNLOAD_TYPE m_downloadType;

    QNetworkAccessManager *m_networkAccessManager;
    QNetworkRequest m_request;
    QByteArray m_data;

    QString m_fileDir;
    QString m_fileName;
};

#endif // WEBDOWNLOADER_H
