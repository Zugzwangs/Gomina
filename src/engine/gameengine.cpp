/*******************************************************/
//
//
/*******************************************************/
#include <QDebug>
#include "gameengine.h"

GameEngine::GameEngine(QObject *parent) : QObject(parent)
{
    /*------------------------------------------------*/
    /*                  INIT THIS                     */
    /*------------------------------------------------*/
    setGameMode(Nomode);      // default mode


    /*------------------------------------------------*/
    /*                INIT COMPONENT                  */
    /*------------------------------------------------*/

    myGoban = new Goban(this);          // build goban data structure

    historic = new GameHistory(this);   // init history data structure

    arbiter = new GameArbiter(this);    // init the game's rules manager

    myBlitz = new Blitz(this);          // create clock TODO maybe need 2 clocks one for blitz game and other for IA

    player_1 = new humanplayer(this);   // init at least first player TODO : think that first player could be a cpuplayer


    /*------------------------------------------------*/
    /*              CONNECT COMPONENT                 */
    /*------------------------------------------------*/

    /*------------------------------------------------*/
    /*                CONNECT OUPUT                   */
    /*------------------------------------------------*/

    /*------------------------------------------------*/
    /*                CONNECT INPUT                   */
    /*------------------------------------------------*/

}

void GameEngine::setGameMode(Mode mode)
{
    GameMode = mode;
}

void GameEngine::setGameStatus(Status stat)
{
    GameStatus = stat;
}

// TODO add lots of stuff
void GameEngine::togglePause()
{
    switch (GameStatus)
        {
        case Running:
            setGameStatus(Paused);
            emit gamePaused();
            break;

        case Paused:
            setGameStatus(Running);
            emit gameWake();
            break;

        case Unstable:
            qDebug() << "something wrong the game goes buggy";
            break;

        default:
            break;
        }
}

// TODO add lots of stuff
void GameEngine::startGame()
{
    switch (GameMode)
        {
        case Nomode:
            break;

        case Free:

            break;

        case Solo:
            break;

        case Online:
            break;

        default:
            break;
        }
}

void GameEngine::restartGame()
{

}

void GameEngine::loadProfile()
{

}

// one player quit, abord the game
void GameEngine::playerQuit()
{
    abordGame();
}

// when the two players abdiques the game end
void GameEngine::playerAbdique()
{

}

void GameEngine::abordGame()
{

}

// if p == nul on considère que le joueur veut en fait passer son tour
void GameEngine::playerPlay(QPoint p)
{
    if (p.isNull())
        {
        // on ne fait que le changement de trait.
        emit activePlayerChanged();
        }

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
    // first check if backtrack is allowed (mode  de jeu ?)
    if (GameMode == Free or GameMode == Solo)
        {
        // then ask GameHistory for previous game position
        // appliquer les changements
        // signaler les changements effectués
        emit gobanChanged(QPoint(0, 0), 0);
        emit activePlayerChanged();
        }

}

// procedure de cloture de fin de partie.
void GameEngine::endGame()
{

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

