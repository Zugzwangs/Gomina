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
    goban_item = goban_scene->createGoban(19);
    ui->goban_view->setScene(goban_scene);

    // setup the HUD part
    Hud = new GameHud(ui->HudFrame);

    // keep the pointer to the game's engine
    Gomenige = GE;

    // connections
    connect( goban_item, SIGNAL(clickOnCase(QPoint)), Gomenige, SLOT(playedOn(QPoint)) );
    connect( Gomenige, SIGNAL(gobanChanged(QPoint,int)), goban_item, SLOT(playOnCase(QPoint,int)) );
}

MainWindow::~MainWindow()
{
    delete ui;
}
