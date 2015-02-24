#include "dialogfindplayer.h"
#include "ui_dialogfindplayer.h"

DialogFindPlayer::DialogFindPlayer(QWidget *parent) : QDialog(parent), ui(new Ui::DialogFindPlayer)
{
    ui->setupUi(this);
}

DialogFindPlayer::~DialogFindPlayer()
{
    delete ui;
}
