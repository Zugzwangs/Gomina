/*******************************************************/
//
//
/*******************************************************/

#ifndef GOBANSCENE_H
#define GOBANSCENE_H

#include <QGraphicsScene>
#include "graphicsgobanitem.h"

class GobanScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GobanScene(QObject* parent = 0);
    void createGoban(int gobanSize = 19);
    ~GobanScene();

private:

};

#endif // GOBANSCENE_H
