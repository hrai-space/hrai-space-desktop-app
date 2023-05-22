
#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QStringList>


class Game
{
public:
    Game(int id, QString title,
         QString shortDescription, QString iconLink);
    int id() const;
    QString title() const;
    QString shortDescription() const;
    QString iconLink() const;
    QString description() const;
    QStringList screenshotLinks() const;
    QStringList fileLinks() const;
    QStringList fileNames() const;
    void setDescription(const QString &description);
    void setScreenshotLinks(const QStringList &screenshotLinks);
    void setFileLinks(const QStringList &fileLinks);
    void setFileNames(const QStringList &fileNames);

private:
    int m_id;
    QString m_title;
    QString m_shortDescription;
    QString m_iconLink;

    QString m_description;
    QStringList m_screenshotLinks;
    QStringList m_fileLinks;
    QStringList m_fileNames;
};

#endif // GAME_H
