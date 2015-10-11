/*******************************************************/
//
//
/*******************************************************/
#include "pathprovider.h"
#include <QDebug>

//define static member
QDir PathProvider::binFolder = QDir();
QDir PathProvider::playerFolder = QDir();
QDir PathProvider:: gamesFolder = QDir();
QDir PathProvider::picsFolder = QDir();

PathProvider::PathProvider() {}

// check if all mandatory ressources are available
bool PathProvider::bootApp()
{
    bool environmentReady = false;

    qDebug() << "starting boot checking !";
    binFolder.setPath(QApplication::applicationDirPath());
    qDebug() << "application folder is " << binFolder.absolutePath();

    // CHECK CFG FILE
    if ( binFolder.exists("gomina.cfg") )
        {
        // checker si le fichier est accessible en lecture/ecriture
        // et contient le minimum correct pour que l'appli tourne
        environmentReady = true;
        }
    else
        {
        //créer le fichier si possible sinon
        //  TODO
        // QFile cfgFile;
        // cfgFile.open(QIODevice::ReadWrite);
        environmentReady = false;
        }

    // CHECK DATA FOLDER AND SUBFOLDERS
    playerFolder.setPath( binFolder.absolutePath());
    gamesFolder.setPath( binFolder.absolutePath());

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
    return environmentReady;
}

// return path to the players folder or an empty string if it doesn't exist
QString PathProvider::getPlayerFolder()
{
    return playerFolder.absolutePath();
}

QString PathProvider::getBinFolder()
{
    return binFolder.absolutePath();
}

QString PathProvider::getGamesFolder()
{
    return gamesFolder.absolutePath();
}

QString PathProvider::getPicsFolder()
{
    return picsFolder.absolutePath();
}

PathProvider::~PathProvider()
{

}

