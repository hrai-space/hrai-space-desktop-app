
#ifndef WEBDOWNLOADER_H
#define WEBDOWNLOADER_H


#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>

class WebDownloader : public QObject
{
    Q_OBJECT
public:
    explicit WebDownloader(QObject *parent = nullptr);
    void downloadFromWeb(const QString &webUrl);
signals:
    void onGetData(QByteArray data);
private slots:
    void onResponse(QNetworkReply *reply);
private:
    QNetworkAccessManager *m_networkAccessManager;
    QNetworkRequest m_request;
    QByteArray m_data;
};

#endif // WEBDOWNLOADER_H
