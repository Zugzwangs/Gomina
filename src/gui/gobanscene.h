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
    GraphicsGobanItem *gobanItem;

public:
    GobanScene(QObject* parent = 0);
    GraphicsGobanItem *createGoban(int gobanSize = 19);
    ~GobanScene();

protected:

};

#endif // GOBANSCENE_H
