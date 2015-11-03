/*******************************************************/
//
//
/*******************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gobanscene.h"
#include "gamehud.h"
#include "gobanview.h"
#include "../engine/gameengine.h"

namespace Ui {  class MainWindow;   }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(GameEngine* GE, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void OpenMenuOption();
    void OpenAbout();
    void OpenMenuLoadGame();
    void OpenMenuSaveGame();
    void OpenDialogFindPlayer();

private:
    Ui::MainWindow *ui;
    GameHud* Hud;

    GobanScene* goban_scene;
    GraphicsGobanItem* goban_item;

    GameEngine* Gomenige;

    QString lastDir;

};

#endif // MAINWINDOW_H
