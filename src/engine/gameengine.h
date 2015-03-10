/*******************************************************/
//
//
/*******************************************************/
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
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

public:
    explicit GameEngine(QObject *parent = 0);
    ~GameEngine();

public slots:
    void startGame();
    void abordGame();
    void restartGame();
    void loadProfile();
    void playerQuit();
    void playerAbdique();
    void playerPlay(QPoint p);
    void backTrackPlay();
    void savePosition();
    void loadPosition();
    void changeGameMod();

private:
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
    void gameStart();
    void activePlayerChanged();
    void requestPlay();
    void digMore();

};

#endif // GAMEENGINE_H
