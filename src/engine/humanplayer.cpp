/*******************************************************/
//
//
/*******************************************************/

#include "humanplayer.h"

humanplayer::humanplayer(QObject *parent) : Player(parent)
{
    init();
}

void humanplayer::init()
{
    setName("Unnamed Player");
    setAvatar("avatar.png");
    setElo(1000);
    setLoc(Gui);
    setStatus(Spectate);
    setSide(NoSide);
}

void humanplayer::loadProfil(QString profilFile)
{
    // check if file exist and read it
    // set this with values
    emit profilLoaded();
}

void humanplayer::exportProfil()
{

}

humanplayer::~humanplayer()
{

}
