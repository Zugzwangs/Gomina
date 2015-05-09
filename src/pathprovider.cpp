/*******************************************************/
//
//
/*******************************************************/

#include "pathprovider.h"
#include <QDir>
#include <QDebug>

//define static member
QString PathProvider::applicationFolder = "";
QString PathProvider::playerFolder = "";
QString PathProvider:: gamesFolder = "";

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
    applicationFolder = QApplication::applicationDirPath();
    qDebug() << "application folder is " << applicationFolder;

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

// return path to the players folder or an empty string
// if it doesn't exist
// TODO check if folder still exist when it required
QString PathProvider::getPlayerFolder()
{
    return playerFolder;
}

PathProvider::~PathProvider()
{

}

