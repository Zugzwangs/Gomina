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
    // clean up previous scene
    this->clear();

    // create the board
    gobanItem = new GraphicsGobanItem(gobanSize);
    addItem(gobanItem);

    // gives space around goban
    QRectF totalSceneRect = sceneRect() + QMarginsF(30, 30, 30, 30);
    addRect(totalSceneRect, QPen(Qt::NoPen), QBrush(Qt::NoBrush));
    return gobanItem;
}

//
GobanScene::~GobanScene()
{

}

