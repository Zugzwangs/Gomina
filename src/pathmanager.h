/*******************************************************/
//
//
/*******************************************************/
#ifndef PATHMANAGER_H
#define PATHMANAGER_H

#include <QDir>
#include <QFile>
#include <QApplication>
#include <QString>

class PathManager
{

public:
    //check environment at startup
    static bool init();

    //convenient methodes to provide common dir/paths
    static QDir getBinFolder();
    static QDir getPlayerFolder();
    static QDir getGamesFolder();
    static QDir getPicsFolder();
    static QDir getLogsFolder();
    static QString getPathBinFolder();
    static QString getPathPlayerFolder();
    static QString getPathGamesFolder();
    static QString getPathPicsFolder();
    static QString getPathLogsFolder();

    //relative path to subfolders from main application's folder.
    static const QString PLAYERS_PATH;
    static const QString GAMES_PATH;
    static const QString PICS_PATH;
    static const QString LOGS_PATH;

private:
    static QDir binFolder;
    static QDir playerFolder;
    static QDir gamesFolder;
    static QDir picsFolder;
    static QDir logsFolder;

    // prevent this to class to be initialized
    PathManager();
    ~PathManager();
};

#endif // PATHMANAGER_H
