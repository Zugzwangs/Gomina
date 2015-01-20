/*******************************************************/
//
//
/*******************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // declaration du moteur de jeu
    GameEngine GE;
    // declaration et affichage de la GUI
    MainWindow w(&GE);
    w.show();

    return a.exec();
}
