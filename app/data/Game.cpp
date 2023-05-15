
#include "Game.h"

Game::Game(int id, QString title, QString description,
           QStringList screenshotLinks, QStringList fileLinks,
           QStringList fileNames)
{
    m_id = id;
    m_title = title;
    m_description = description;
    m_screenshotLinks = screenshotLinks;
    m_fileLinks = fileLinks;
    m_fileNames = fileNames;
}

int Game::id() const
{
    return m_id;
}

QString Game::title() const
{
    return m_title;
}

QString Game::description() const
{
    return m_description;
}

QStringList Game::screenshotLinks() const
{
    return m_screenshotLinks;
}

QStringList Game::fileLinks() const
{
    return m_fileLinks;
}

QStringList Game::fileNames() const
{
    return m_fileNames;
}

