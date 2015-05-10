/*******************************************************/
//
//
/*******************************************************/
#ifndef PATHPROVIDER_H
#define PATHPROVIDER_H

#include <QDir>
#include <QFile>
#include <QApplication>

class PathProvider
{

public:
    PathProvider();
    ~PathProvider();

    // check environment
    static bool bootApp();

    // convenient methodes to provide common paths
    static QString getPlayerFolder();
    static QString getBinFolder();
    static QString getGamesFolder();
    static QString getPicsFolder();

private:
    static QDir binFolder;
    static QDir playerFolder;
    static QDir gamesFolder;
    static QDir picsFolder;
    //static string ou qfile vers la cfg ?

};

#endif // PATHPROVIDER_H
