/*******************************************************/
//
//
/*******************************************************/
#include <QApplication>

#include "pathprovider.h"
#include "gui/mainwindow.h"

int main(int argc, char *argv[])
{
    // On instancie l'application qt
    QApplication a(argc, argv);

    // Settings généraux
    QApplication::setApplicationName("Gomina");
    QApplication::setOrganizationName("Zugzwang Software");
    QApplication::setOrganizationDomain("Zugzwangs@Ariadne.org");

    // Si l'environnement est en place
    if ( PathProvider::bootApp() )
        {
        // On instancie les Objets principaux:
        GameEngine* GE = new GameEngine();  // init Game Engine
        MainWindow w(GE);                   // init main Window
        w.show();                           // show main IHM
        return a.exec();                    // run the main loop
        delete GE;
        }

    // Si l'environnement n'est pas complet
    else
        {
        // on trace les soucis

        // et on se barre

        }

}
