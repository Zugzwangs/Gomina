/*******************************************************/
//
//TODO: some feature to think about
//void restartGame();

/*******************************************************/
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "goban.h"
#include "humanplayer.h"
#include "cpuplayer.h"
#include "blitz.h"
#include "gamehistory.h"
#include "gamearbiter.h"
#include "gobandiff.h"

class GameEngine : public QObject
{
    Q_OBJECT
    Q_ENUMS(Mode)
    Q_ENUMS(Status)

public:
    explicit GameEngine(QObject *parent = 0);
    ~GameEngine();

    enum Mode { Nomode = 0, Free = 1, Solo = 2, Local = 3, Online = 4 };
    enum Status { NoStatus = 0, Running = 1, Paused = 2, Waiting = 3 };

public slots:

    //functions relatives to the game status
    void startGame();
    void togglePause();
    void endGame();
    void playerQuit();

    //function when a game is running
    void playerPlay(QPoint p);
    void backTrackPlay();
    void savePosition();
    void loadPosition();
    void loadProfile();

private slots:
    void setGameMode(Mode mode);
    void setGameStatus(Status stat);

private:
    Mode GameMode;
    Status GameStatus;

    Goban* myGoban;
    GameHistory* historic;
    GameArbiter* arbiter;
    Blitz* myBlitz;
    Player* player_1;
    Player* player_2;

signals:
    void gobanChanged(QPoint p, int c);
    void scoreChanged();
    void profilLoaded();
    void opponentConnected();
    void gameAborded();
    void gameEnd();
    void gamePaused();
    void gameWake();
    void gameStart();
    void activePlayerChanged();
    void requestPlay();
    void digMore();

};

#endif // GAMEENGINE_H
