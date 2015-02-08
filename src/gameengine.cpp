/*******************************************************/
//
//
/*******************************************************/
#include <QDebug>
#include "gameengine.h"

GameEngine::GameEngine(QObject *parent) : QObject(parent)
{
    // build goban data structure (19*19 is default size)
    myGoban = new Goban(this);

    // initiate states of components

}

void GameEngine::playedOn(QPoint p)
{
    // a player click on case p and if its free
    if ( myGoban->getValue(p)==-1 )
        {
        myGoban->setValue(p, 0);
        emit gobanChanged(p, 0);
        }
}

GameEngine::~GameEngine()
{

}

