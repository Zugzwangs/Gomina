/*******************************************************/
//
//
/*******************************************************/

#ifndef PATHPROVIDER_H
#define PATHPROVIDER_H

#include <QApplication>

class PathProvider
{

public:
    PathProvider();
    ~PathProvider();

    static bool bootApp();
    static QString getPlayerFolder();

private:
    static QString applicationFolder;
    static QString playerFolder;
    static QString gamesFolder;

};

#endif // PATHPROVIDER_H
