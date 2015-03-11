/*******************************************************/
//
//
/*******************************************************/

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"

class humanplayer : public Player
{
    Q_OBJECT

public:
    explicit humanplayer(QObject *parent = 0);
    ~humanplayer();
    virtual void init();
};

#endif // HUMANPLAYER_H
