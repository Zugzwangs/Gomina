/*******************************************************/
//
//
/*******************************************************/
#include <QApplication>

#include "pathprovider.h"
#include "gui/mainwindow.h"

int main(int argc, char *argv[])
{
    // on démarre le flot principal
    QApplication a(argc, argv);

    // on applique quelques settings généraux
    QApplication::setApplicationName("Gomina");
    QApplication::setOrganizationName("Zugzwang Software");
    QApplication::setOrganizationDomain("Zugzwangs@Ariadne.org");

    // on check si l'environnement de l'appli est complet
    if ( PathProvider::bootApp() )
        {
        // instanciation du moteur de jeu
        GameEngine* GE = new GameEngine();

        // instanciation de l'interface graphique
        MainWindow w(GE);
        w.show();
        }

    return a.exec();
    delete GE;
}
