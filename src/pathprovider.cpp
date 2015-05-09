/*******************************************************/
//
//
/*******************************************************/
#include "pathprovider.h"
#include <QDebug>

//define static member
QDir PathProvider::applicationFolder = QDir();
QDir PathProvider::playerFolder = QDir();
QDir PathProvider:: gamesFolder = QDir();

PathProvider::PathProvider() {}

// check if all mandatory ressources are availiable
bool PathProvider::bootApp()
{
    bool environmentReady = false;
    QString issueDescriptor;
    // init file ?
    // folder ? init them
    // db ? theme ? ico ? etc...qDebug
    // load some options ?

    qDebug() << "starting boot checking !";
    applicationFolder.setPath(QApplication::applicationDirPath());
    qDebug() << "application folder is " << applicationFolder.absolutePath();

    // check if data folders exist
    playerFolder.setPath( applicationFolder.absolutePath());
    gamesFolder.setPath( applicationFolder.absolutePath());

    playerFolder.cdUp();
    if (playerFolder.exists("data/profils"))
        {
        playerFolder.cd("data/profils");
        environmentReady = true;
        qDebug() << "profils folder found and is " << playerFolder.absolutePath();
        }
    else
        {
        // recover procedure ? and if so set envReady to true ?
        environmentReady = false;
        }

    gamesFolder.cdUp();
    if (gamesFolder.exists("data/games"))
        {
        gamesFolder.cd("data/games");
        environmentReady = true;
        qDebug() << "games folder found and is " << gamesFolder.absolutePath();
        }
    else
        {
        // recover procedure ? and if so set envReady to true ?
        environmentReady = false;
        }

    qDebug() << "boot checking finish!";

    if ( environmentReady )
        {
        qDebug() << "Aplication is ready to run";
        return true;
        }
    else
        {
        qDebug() << "Application can't start !";
        return false;
        }
}

// return path to the players folder or an empty string if it doesn't exist
QString PathProvider::getPlayerFolder()
{
    return playerFolder.absolutePath();
}

QString PathProvider::getBinFolder()
{
    return applicationFolder.absolutePath();
}

QString PathProvider::getGamesFolder()
{
    return gamesFolder.absolutePath();
}

PathProvider::~PathProvider()
{

}

