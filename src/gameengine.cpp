/*******************************************************/
//
//
/*******************************************************/

#include "gameengine.h"

GameEngine::GameEngine(QObject *parent) : QObject(parent)
{

    //build goban data structure
    myGoban = new Goban(this);

    //initiate states of components

}

GameEngine::~GameEngine()
{

}

