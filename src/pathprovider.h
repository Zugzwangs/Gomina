/*******************************************************/
//
//
/*******************************************************/
#ifndef PATHPROVIDER_H
#define PATHPROVIDER_H

#include <QDir>
#include <QApplication>

class PathProvider
{

public:
    PathProvider();
    ~PathProvider();

    // check environment
    static bool bootApp();

    // convenient methodes to provide paths
    static QString getPlayerFolder();
    static QString getBinFolder();
    static QString getGamesFolder();

private:
    static QDir applicationFolder;
    static QDir playerFolder;
    static QDir gamesFolder;

};

#endif // PATHPROVIDER_H
