/*******************************************************/
//
//
/*******************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gobanscene.h"
#include "gamehud.h"
#include "../gameengine.h"

namespace Ui {  class MainWindow;   }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(GameEngine* GE, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GobanScene* goban_scene;
    GameHud* Hud;
    GameEngine* Gomenige;
};

#endif // MAINWINDOW_H