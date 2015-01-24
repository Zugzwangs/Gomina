/*******************************************************/
//
//
/*******************************************************/

#include "gameengine.h"

GameEngine::GameEngine(QObject *parent) : QObject(parent)
{

    //build goban data structure (19*19 is default size)
    myGoban = new Goban(this);

    //initiate states of components

}

GameEngine::~GameEngine()
{

}

