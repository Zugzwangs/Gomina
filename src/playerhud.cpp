/*******************************************************/
//
//
/*******************************************************/

#include "playerhud.h"
#include "ui_playerhud.h"

PlayerHud::PlayerHud(QWidget *parent) : QScrollArea(parent), ui(new Ui::PlayerHud)
{
    ui->setupUi(this);
}

PlayerHud::~PlayerHud()
{
    delete ui;
}
