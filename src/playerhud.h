/*******************************************************/
//
//
/*******************************************************/

#ifndef PLAYERHUD_H
#define PLAYERHUD_H

#include <QScrollArea>

namespace Ui {  class PlayerHud;    }

class PlayerHud : public QScrollArea
{
    Q_OBJECT

public:
    explicit PlayerHud(QWidget *parent = 0);
    ~PlayerHud();

private:
    Ui::PlayerHud *ui;
};

#endif // PLAYERHUD_H
