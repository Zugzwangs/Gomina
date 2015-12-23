/*******************************************************/
//
//
/*******************************************************/
#include <logmanager.h>
#include "gameengine.h"

GameEngine::GameEngine(QObject *parent) : QObject(parent)
{
    /*------------------------------------------------*/
    /*                  INIT THIS                     */
    /*------------------------------------------------*/
    qCDebug(engine()) << "Game is starting.";
    GameMode = Nomode;      //default mode
    GameStatus = NoStatus;  //default status

    /*------------------------------------------------*/
    /*                INIT COMPONENTS                 */
    /*------------------------------------------------*/
    myGoban = new Goban(this);          //build goban data structure
    historic = new GameHistory(this);   //init history data structure
    arbiter = new GameArbiter(this);    //init the game's rules manager
    myBlitz = new Blitz(this);          //create clock TODO maybe need 2 clocks one for blitz game and other for IA
    player_1 = new humanplayer(this);   //init at least first player TODO : think that first player could be a cpuplayer
    player_2 = NULL;
    qCDebug(engine()) << "components are initialised";

    /*------------------------------------------------*/
    /*              CONNECT COMPONENTS                */
    /*------------------------------------------------*/


    /*------------------------------------------------*/
    /*                CONNECT INPUT                   */
    /*------------------------------------------------*/


    /*------------------------------------------------*/
    /*                CONNECT OUPUT                   */
    /*------------------------------------------------*/

}

//on profite du destructeur pour détruire toutes les variables dynamiques.
GameEngine::~GameEngine()
{
    delete myGoban;
    delete historic;
    delete arbiter;
    delete myBlitz;
    delete player_1;
    if(player_2 != NULL)
        delete player_2;
}

/*------------------------------------------------*/
/*             GAME ENGINE STATES                 */
/*------------------------------------------------*/
// we allow change game's mode only when there is no game currently running
void GameEngine::setGameMode(Mode mode)
{
    if( GameStatus != NoStatus )
        {
        qCWarning(engine()) << "change mode forbidden.";
        return;
        }
    GameMode = mode;
}

void GameEngine::setGameStatus(Status stat)
{
    GameStatus = stat;
}

void GameEngine::startGame()
{
    //case where game can't be started
    if ( GameStatus != NoStatus )
        {
        qCWarning(engine()) << "can't start game when another game is running.";
        return;
        }

    if ( GameMode == Nomode )
        {
        qCWarning(engine()) << "can't start new game if no game mode is set.";
        return;
        }

    //lauch the appropriate startup
    switch (GameMode)
        {
        case Free:

            break;

        case Solo:
            break;

        case Local:
            break;

        case Online:
            break;

        default:
            qCWarning(engine()) << "incoherent state of game engine.";
            break;
        }
}

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

        default:
            qCWarning(engine()) << "incohrent toggle pause request when no game is running.";
        }
}

//procedure de cloture de fin de partie.
void GameEngine::endGame()
{
    setGameStatus(NoStatus);
    return;
}

//if a player quit the game, end the game
void GameEngine::playerQuit()
{
    endGame();
}

/*------------------------------------------------*/
/*             IN GAME PROCEDURES                 */
/*------------------------------------------------*/
void GameEngine::playerPlay(QPoint p)
{
    if (p.isNull())
        {
        // si p == null on considère que le joueur veut en fait passer son tour
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

void GameEngine::savePosition()
{
    // delegate save to the import/export object

}

void GameEngine::loadPosition()
{
    // ask import/export object to do the job
    // and wait for end of task ans then emit ready state ?
}

void GameEngine::loadProfile()
{

}

