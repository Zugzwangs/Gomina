/*******************************************************/
// Subclass of QgraphicsScene
// implement routines to build, reset and handle the
// Goban, stone and others graphics features.

/*******************************************************/
#include <QDebug>

#include "gobanscene.h"
#include "QGraphicsRectItem"

GobanScene::GobanScene(QObject* parent) : QGraphicsScene(parent)
{
    // by default build a 19*19 Goban
    createGoban(19);
}

void GobanScene::createGoban(int gobanSize)
{
    qDebug() << "createGoban() : build new goban with size of " << gobanSize;
    if ( gobanSize<2 || gobanSize>19)
        {
        qDebug("error: the size requested for the Goban is incorrect.");
        return;
        }

    // clean up previous scene
    this->clear();

    // create the board
    GraphicsGobanItem *gobanItem = new GraphicsGobanItem(gobanSize);
    this->addItem(gobanItem);

}


GobanScene::~GobanScene()
{

}

