#ifndef HISTORICALHUD_H
#define HISTORICALHUD_H

#include <QScrollArea>

namespace Ui {
class HistoricalHud;
}

class HistoricalHud : public QScrollArea
{
    Q_OBJECT

public:
    explicit HistoricalHud(QWidget *parent = 0);
    ~HistoricalHud();

private:
    Ui::HistoricalHud *ui;
};

#endif // HISTORICALHUD_H
