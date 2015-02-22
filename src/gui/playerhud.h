/*******************************************************/
//
//
/*******************************************************/

#ifndef PLAYERHUD_H
#define PLAYERHUD_H

#include <QFrame>

namespace Ui { class PlayerHud;  }

class PlayerHud : public QFrame
{
    Q_OBJECT

public:
    explicit PlayerHud(QWidget *parent = 0);
    ~PlayerHud();

private:
    Ui::PlayerHud *ui;
};

#endif // PLAYERHUD_H
