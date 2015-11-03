/*******************************************************/
//
//
/*******************************************************/
#include <QFileDialog>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "optionsdialog.h"
#include "aboutwindow.h"
#include "dialogfindplayer.h"
#include "pathprovider.h"


MainWindow::MainWindow(GameEngine *GE, QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // main window settings
    this->setWindowTitle("Gomina");
    this->setMinimumSize( QSize(800, 600) );

    // setup the playground part
    goban_scene = new GobanScene(this);
    goban_item = goban_scene->createGoban(19);
    ui->goban_view->setScene(goban_scene);

    // keep last directory used for saving
    lastDir = PathProvider::getGamesFolder();

    // setup the HUD part
    Hud = new GameHud();
    ui->HudFrame->layout()->addWidget(Hud);

    // keep the pointer to the game's engine
    Gomenige = GE;

    // connect modules together
    connect( goban_item, SIGNAL(clickOnCase(QPoint)), Gomenige, SLOT(playerPlay(QPoint)) );
    connect( Gomenige, SIGNAL(gobanChanged(QPoint,int)), goban_item, SLOT(playOnCase(QPoint,int)) );

    // connect actions from menu
    connect( ui->actionMenu, SIGNAL(triggered()), this, SLOT(OpenMenuOption()) );
    connect(ui->actionAbout_Gomina, SIGNAL(triggered()), this, SLOT(OpenAbout()) );
    connect(ui->actionLoad_Game, SIGNAL(triggered()), this, SLOT(OpenMenuLoadGame()) );
    connect(ui->actionSave_Game, SIGNAL(triggered()), this, SLOT(OpenMenuSaveGame()) );
    connect(ui->actionFind_Player, SIGNAL(triggered()), this, SLOT(OpenDialogFindPlayer()) );
}

void MainWindow::OpenMenuOption()
{
    OptionsDialog Options(this);
    Options.exec();
}

void MainWindow::OpenMenuLoadGame()
{
QString fileName;

    //use path provider here to get Last dir used
    fileName = QFileDialog::getOpenFileName(this, tr("Load game"), PathProvider::getGamesFolder(), "Game File (*.sgf)");
    qDebug() << "OpenMenuLoadGame: " << fileName;
    if ( fileName.isEmpty() )
        {
        return;
        }
    else
        {
        return;
        }
}


//TODO update the lastdir path when user save a game to a differente directory
void MainWindow::OpenMenuSaveGame()
{
QString fileName = "";

    fileName = QFileDialog::getSaveFileName(this, tr("Save File"), lastDir, "Game Files (*.sgf)" );
    qDebug() << "OpenMenuSaveGame: " << fileName;
    if ( fileName.isEmpty() )
        {
        return;
        }
    else
        {
        return;
        }
}

void MainWindow::OpenDialogFindPlayer()
{
    DialogFindPlayer FindPlayer(this);
    FindPlayer.exec();
}

void MainWindow::OpenAbout()
{
    AboutWindow About(this);
    About.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
