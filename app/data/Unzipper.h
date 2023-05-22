#ifndef UNZIPPER_H
#define UNZIPPER_H

#include <QString>
#include <QObject>

#include "network/Web_Downloader.h"

class Unzipper : public QObject
{
    Q_OBJECT
public:
    explicit Unzipper(QObject *parent = nullptr);
    QString zipFilePath() const;
    QString unzipFolderPath() const;
    void exctractFiles(const QString& archivePath, const QString& destPath, const QString& fileName);

private:
    void unzipFile(const QString& zipPath, const QString& destPath);

    WebDownloader *m_webDownloader;

    QString m_zipFilePath;
    QString m_unzipFolderPath;

    QString m_destPath;
    QString m_filePath;
};

#endif // UNZIPPER_H
