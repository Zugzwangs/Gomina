/*******************************************************/
//
//
/*******************************************************/

#include "pathprovider.h"
#include <QDir>
#include <QDebug>


PathProvider::PathProvider() {}

// check if all mandatory ressources are availiable
bool PathProvider::bootApp()
{
    bool environmentReady;
    QString issueDescriptor;
    // init file ?
    // folder ? init them
    // db ? theme ? ico ? etc...
    // load some options ?

    qdebug() << "starting boot checking !";
    applicationFolder = QApplication::applicationDirPath();
    qdebug() << "application folder is " << applicationFolder;

    qdebug() << "boot checking finish!";

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

