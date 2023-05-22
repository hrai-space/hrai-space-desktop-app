#include "Unzipper.h"

#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

Unzipper::Unzipper(QObject *parent)
    : QObject(parent), m_webDownloader{new WebDownloader}
{
    //connect(m_webDownloader, );
}

/* Getters */
QString Unzipper::zipFilePath() const
{
    return m_zipFilePath;
}

QString Unzipper::unzipFolderPath() const
{
    return m_unzipFolderPath;
}

void Unzipper::unzipFile(const QString& zipPath, const QString& destPath)
{
    QString unzipCommand;

    if (QSysInfo::productType() == "windows")
    {
        unzipCommand = QString("tar -xf \"%1\" -C \"%2\"").arg(zipPath, destPath);
    }
    else if (QSysInfo::productType() == "macos")
    {
        unzipCommand = QString("unzip -o \"%1\" -d \"%2\"").arg(zipPath, destPath);
    }
    else if (QSysInfo::productType() == "linux")
    {
        unzipCommand = QString("unzip -o \"%1\" -d \"%2\"").arg(zipPath, destPath);
    }
    else
    {
        qDebug() << "Помилка. Інша операційна система.";
    }

    int result = system(unzipCommand.toUtf8().constData());
    if (result != 0)
    {
        qDebug() << "Помилка розпаковки файла.";
    }
    QFile file(m_filePath);
    file.remove();
}

void Unzipper::exctractFiles(const QString &archivePath, const QString &destPath, const QString &fileName)
{
    m_destPath = destPath;
    m_webDownloader->downloadFromWebToFile(archivePath, "temp", fileName);
    connect(m_webDownloader, &WebDownloader::onFileWritten, this, [=](const QString& filePath)
            {
                m_filePath = filePath;
                unzipFile(filePath, m_destPath);
            });
}


