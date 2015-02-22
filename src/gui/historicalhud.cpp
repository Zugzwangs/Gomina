#include "historicalhud.h"
#include "ui_historicalhud.h"

HistoricalHud::HistoricalHud(QWidget *parent) : QScrollArea(parent), ui(new Ui::HistoricalHud)
{
    ui->setupUi(this);
}

HistoricalHud::~HistoricalHud()
{
    delete ui;
}
