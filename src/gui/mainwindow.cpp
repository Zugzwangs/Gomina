/*******************************************************/
//
//
/*******************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(GameEngine *GE, QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //main window settings
    this->setWindowTitle("Gomina");
    this->setMinimumSize( QSize(800, 600) );

    // setup the playground part
    goban_scene = new GobanScene(this);
    ui->goban_view->setScene(goban_scene);

    // setup the HUD part
    Hud = new GameHud(ui->HudFrame);

    // keep the pointer to the game's engine
    Gomenige = GE;
}

MainWindow::~MainWindow()
{
    delete ui;
}