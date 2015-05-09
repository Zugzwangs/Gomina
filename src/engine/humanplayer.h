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

    void init();
    void loadProfil(QString profilFile);
    void exportProfil(QString profilFile);

};

#endif // HUMANPLAYER_H
