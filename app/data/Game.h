
#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QStringList>


class Game
{
public:
    Game(int id, QString title, QString description,
         QStringList screenshotLinks, QStringList fileLinks,
         QStringList fileNames);
    int id() const;
    QString title() const;
    QString description() const;
    QStringList screenshotLinks() const;
    QStringList fileLinks() const;
    QStringList fileNames() const;
private:
    int m_id;
    QString m_title;
    QString m_description;
    QStringList m_screenshotLinks;
    QStringList m_fileLinks;
    QStringList m_fileNames;
};

#endif // GAME_H
