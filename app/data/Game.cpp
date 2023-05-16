
#include "Game.h"

Game::Game(int id, QString title,
           QString shortDescription, QString iconLink)
{
    m_id = id;
    m_title = title;
    m_shortDescription = shortDescription;
    m_iconLink = iconLink;
}
/* Setters */
void Game::setDescription(const QString &description)
{
    m_description = description;
}

void Game::setScreenshotLinks(const QStringList &screenshotLinks)
{
    m_screenshotLinks = screenshotLinks;
}

void Game::setFileLinks(const QStringList &fileLinks)
{
    m_fileLinks = fileLinks;
}

void Game::setFileNames(const QStringList &fileNames)
{
    m_fileNames = fileNames;
}
/* Getters */
int Game::id() const
{
    return m_id;
}

QString Game::title() const
{
    return m_title;
}

QString Game::shortDescription() const
{
    return m_shortDescription;
}

QString Game::description() const
{
    return m_description;
}

QString Game::iconLink() const
{
    return m_iconLink;
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

