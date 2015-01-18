/*******************************************************/
//
//
/*******************************************************/

#ifndef GAMEHUD_H
#define GAMEHUD_H

#include <QScrollArea>

namespace Ui {
class GameHud;
}

class GameHud : public QScrollArea
{
    Q_OBJECT

public:
    explicit GameHud(QWidget *parent = 0);
    ~GameHud();

private:
    Ui::GameHud *ui;
};

#endif // GAMEHUD_H
