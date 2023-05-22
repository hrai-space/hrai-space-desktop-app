
#ifndef WEBPIXMAP_H
#define WEBPIXMAP_H

#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>


class WebPixmap : public QPixmap, public QObject
{
public:
    WebPixmap();
    void loadFromWeb(const QString &webUrl);
private slots:
    void onGetPixmapData(QNetworkReply *reply);
private:
    QNetworkAccessManager *m_networkAccessManager;
    QNetworkRequest m_request;
};

#endif // WEBPIXMAP_H
