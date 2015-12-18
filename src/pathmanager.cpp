/*******************************************************/
//
//
/*******************************************************/
#include "pathmanager.h"
#include <QDebug>

//initialize static members
QDir PathManager::binFolder  = QDir();
QDir PathManager::playerFolder = QDir();
QDir PathManager::gamesFolder = QDir();
QDir PathManager::picsFolder = QDir();
QDir PathManager::logsFolder = QDir();

//relative path from main folder application
const QString PathManager::PLAYERS_PATH = "data/players";
const QString PathManager::GAMES_PATH = "data/games";
const QString PathManager::PICS_PATH = "data/pics";
const QString PathManager::LOGS_PATH = "logs";

//constructor and destructor are private : no implementation needed
PathManager::PathManager()  {}
PathManager::~PathManager() {}

//check and create if needed  all mandatory folders
bool PathManager::init()
{
    qDebug() << "starting boot checking !";

    //Main folder
    binFolder.setPath(QApplication::applicationDirPath());
    qDebug() << "application folder is " << binFolder.absolutePath();

    //Player folder
    playerFolder.setPath( binFolder.absolutePath() );
    playerFolder.cdUp();
    if (playerFolder.exists(PLAYERS_PATH))
        {
        playerFolder.cd(PLAYERS_PATH);
        qDebug() << "player folder found : " << playerFolder.absolutePath();
        }
    else
        {
        if ( playerFolder.mkdir(PLAYERS_PATH) )
            {
            playerFolder.cd(PLAYERS_PATH);
            qDebug() << "player folder created: " << playerFolder.absolutePath();
            }
        else
            {
            qDebug() << "can't create player folder.";
            return false;
            }
        }

    //Games folder
    gamesFolder.setPath( binFolder.absolutePath() );
    gamesFolder.cdUp();
    if (gamesFolder.exists(GAMES_PATH))
        {
        gamesFolder.cd(GAMES_PATH);
        qDebug() << "Games folder found : " << gamesFolder.absolutePath();
        }
    else
        {
        if ( gamesFolder.mkdir(GAMES_PATH) )
            {
            gamesFolder.cd(GAMES_PATH);
            qDebug() << "games folder created: " << gamesFolder.absolutePath();
            }
        else
            {
            qDebug() << "can't create games folder.";
            return false;
            }
        }

    //Pics sub folder
    picsFolder.setPath( binFolder.absolutePath() );
    picsFolder.cdUp();
    if (picsFolder.exists(PICS_PATH))
        {
        picsFolder.cd(PICS_PATH);
        qDebug() << "Pics folder found : " << gamesFolder.absolutePath();
        }
    else
        {
        if ( picsFolder.mkdir(PICS_PATH) )
            {
            picsFolder.cd(PICS_PATH);
            qDebug() << "Pics folder created: " << picsFolder.absolutePath();
            }
        else
            {
            qDebug() << "can't create Pics folder.";
            return false;
            }
        }

    //Log sub folder
    logsFolder.setPath( binFolder.absolutePath() );
    logsFolder.cdUp();
    if (logsFolder.exists(LOGS_PATH))
        {
        logsFolder.cd(LOGS_PATH);
        qDebug() << "Logs folder found : " << logsFolder.absolutePath();
        }
    else
        {
        if ( logsFolder.mkdir(LOGS_PATH))
            {
            logsFolder.cd(LOGS_PATH);
            qDebug() << "Logs folder created: " << logsFolder.absolutePath();
            }
        else
            {
            qDebug() << "can't create Logs folder.";
            return false;
            }
        }

    return true;
}

//return folders object
QDir PathManager::getBinFolder()    { return binFolder; }
QDir PathManager::getPlayerFolder() { return playerFolder; }
QDir PathManager::getGamesFolder()  { return gamesFolder; }
QDir PathManager::getPicsFolder()   { return picsFolder; }
QDir PathManager::getLogsFolder()   { return logsFolder; }

//return path to the application folders or an empty string if it doesn't exist
QString PathManager::getPathBinFolder()    { return binFolder.absolutePath(); }
QString PathManager::getPathPlayerFolder() { return playerFolder.absolutePath(); }
QString PathManager::getPathGamesFolder()  { return gamesFolder.absolutePath(); }
QString PathManager::getPathPicsFolder()   { return picsFolder.absolutePath(); }
QString PathManager::getPathLogsFolder()   { return logsFolder.absolutePath(); }
