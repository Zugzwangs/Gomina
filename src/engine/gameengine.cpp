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

void GameEngine::startGame()
{

}

void GameEngine::abordGame()
{

}

void GameEngine::restartGame()
{

}

void GameEngine::loadProfile()
{

}

void GameEngine::playerQuit()
{

}

void GameEngine::playerAbdique()
{

}

void GameEngine::playerPlay(QPoint p)
{
    // a player click on case p and if its free
    if ( myGoban->getValue(p)==-1 )
        {
        myGoban->setValue(p, 0);
        emit gobanChanged(p, 0);
        }
}

void GameEngine::backTrackPlay()
{

}

void GameEngine::savePosition()
{

}

void GameEngine::loadPosition()
{

}

void GameEngine::changeGameMod()
{

}

GameEngine::~GameEngine()
{

}

