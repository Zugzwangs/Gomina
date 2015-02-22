/*******************************************************/
//
//
/*******************************************************/

#include "playerhud.h"
#include "ui_playerhud.h"
#include <QDebug>

PlayerHud::PlayerHud(QWidget *parent) : QFrame(parent), ui(new Ui::PlayerHud)
{
    ui->setupUi(this);
}

PlayerHud::~PlayerHud()
{
    delete ui;
}
