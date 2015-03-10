/*******************************************************/
//
//
/*******************************************************/
#include <QDebug>
#include "gameengine.h"

GameEngine::GameEngine(QObject *parent) : QObject(parent)
{
    /*------------------------------------------------*/
    /*                INIT COMPONENT                  */
    /*------------------------------------------------*/

    myGoban = new Goban(this);          // build goban data structure

    historic = new GameHistory(this);   //

    arbiter = new GameArbiter(this);    //

    myBlitz = new Blitz(this);          //

    player_1 = new Player(this);        //


    /*------------------------------------------------*/
    /*              CONNECT COMPONENT                 */
    /*------------------------------------------------*/

/*
emit gobanChanged(QPoint p, int c);
emit scoreChanged();
emit profilLoaded();
emit opponentConnected();
emit gameAborded();
emit gameEnd();
emit activePlayerChanged();
emit requestPlay();
emit digMore();
*/
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
    // a player click on case p and if its valid
    if ( myGoban->getValue(p)==-1 )
        {
        // apply and signal changes
        // emit that active player role switch
        myGoban->setValue(p, 0);
        emit gobanChanged(p, 0);
        emit activePlayerChanged();
        }
}

void GameEngine::backTrackPlay()
{
    //if backtrack is possible do and emit changes
    emit gobanChanged(QPoint(0, 0), 0);
    emit activePlayerChanged();
}

void GameEngine::savePosition()
{
    // delegate save to the import/export object
}

void GameEngine::loadPosition()
{
    // ask import/export object to do the job
    // and wait for end of task ans then emit ready state ?
}

void GameEngine::changeGameMod()
{
    // maybe usefull as private slot ??

}

GameEngine::~GameEngine()
{

}

