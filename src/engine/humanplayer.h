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
    virtual void loadProfil(QString profilFile);
    virtual void exportProfil();

};

#endif // HUMANPLAYER_H
