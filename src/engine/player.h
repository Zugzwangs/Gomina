/*******************************************************/
//
//
/*******************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject
{
    Q_OBJECT

public:
    explicit Player(QObject *parent = 0);
    ~Player();
    virtual void init() = 0;


};

#endif // PLAYER_H
