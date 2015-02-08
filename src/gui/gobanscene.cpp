/*******************************************************/
// Subclass of QgraphicsScene
// implement routines to build, reset and handle the
// Goban, stone and others graphics features.

/*******************************************************/
#include <QDebug>

#include "gobanscene.h"

GobanScene::GobanScene(QObject* parent) : QGraphicsScene(parent)
{

}

// create the Goban Item and return a pointer to it
GraphicsGobanItem* GobanScene::createGoban(int gobanSize)
{
    qDebug() << "createGoban() : build new goban with size of " << gobanSize;
    if ( gobanSize<2 || gobanSize>19)
        {// if size is incorrect force a default size
        gobanSize = 19;
        }

    // clean up previous scene
    this->clear();

    // create the board
    gobanItem = new GraphicsGobanItem(gobanSize);
    addItem(gobanItem);
    return gobanItem;
}

//
GobanScene::~GobanScene()
{

}

