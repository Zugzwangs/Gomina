/*******************************************************/
//
//
/*******************************************************/

#include "gamehud.h"
#include "ui_gamehud.h"

GameHud::GameHud(QWidget *parent) : QScrollArea(parent), ui(new Ui::GameHud)
{
    ui->setupUi(this);
}

GameHud::~GameHud()
{
    delete ui;
}
