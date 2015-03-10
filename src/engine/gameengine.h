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
    Player* player_1;
    Player* player_2;
    Blitz* myBlitz;

signals:
    void gobanChanged(QPoint p, int c);
    void scoreChanged();
    void profilLoaded();
    void opponentConnected();
    void gameAborded();
    void gameEnd();
    void activePlayerChanged();
    void requestPlay();
    void digMore();

};

#endif // GAMEENGINE_H
