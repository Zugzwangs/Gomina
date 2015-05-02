/*******************************************************/
//
//
/*******************************************************/

#ifndef CPUPLAYER_H
#define CPUPLAYER_H

#include "player.h"

class CpuPlayer : public Player
{
    Q_OBJECT

public:
    explicit CpuPlayer(QObject *parent = 0);
    ~CpuPlayer();

    virtual void init();
    virtual void loadProfil(QString profilFile);
    virtual void exportProfil();

};

#endif // CPUPLAYER_H
