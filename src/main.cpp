/*******************************************************/
//
//
/*******************************************************/
#include <QApplication>
#include <QDebug>

#include "pathmanager.h"
#include "logmanager.h"
#include "confmanager.h"
#include "gui/mainwindow.h"

int main(int argc, char *argv[])
{
    //on instancie l'application qt
    QApplication a(argc, argv);

    //settings généraux
    QApplication::setApplicationName("Gomina");
    QApplication::setOrganizationName("Zugzwang Software");
    QApplication::setOrganizationDomain("Zugzwangs@Ariadne.org");

    //initialisation des services globaux ( Path >> Logs >> Config )
    if ( !PathManager::init() )
        {
        qDebug() << "Un ou des dossiers de l'application sont manquant(s). ";
        qDebug() << "L'application ne peux pas démarrer. ";
        return 1;
        }
    else
        qDebug() << "initialisation du PathManager ok.";

    if ( !LogManager::init(PathManager::getPathLogsFolder()) )
        {
        qDebug() << "L'initialisation de la journalisation à échouée.";
        qDebug() << "L'application ne peux pas démarrer. ";
        return 1;
        }
    else
        qDebug() << "initialisation du LogManager ok.";

    if ( !confManager::init() )
        {
        qDebug() << "L'initialisation du fichier de configuration à échouée.";
        qDebug() << "L'application ne peux pas démarrer. ";
        return 1;
        }
    else
        qDebug() << "initialisation du ConfManager ok.";

    //on instancie les objets principaux:
    GameEngine* GE = new GameEngine();  // init Game Engine
    MainWindow w(GE);                   // init main Window
    w.show();                           // show main IHM
    return a.exec();                    // run the main loop

    //clean and quit
    delete GE;
}
