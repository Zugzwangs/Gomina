/*******************************************************/
//
//
/*******************************************************/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include "goban.h"

class GameEngine : public QObject
{
    Q_OBJECT

public:
    explicit GameEngine(QObject *parent = 0);
    ~GameEngine();

signals:
    void gobanChanged(QPoint p, int c);

public slots:
    void playedOn(QPoint p);

private:
    Goban* myGoban;

};

#endif // GAMEENGINE_H
