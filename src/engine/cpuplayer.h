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

    void init();
    void loadProfil(QString profilFile);
    void exportProfil(QString profilFile);

};

#endif // CPUPLAYER_H
