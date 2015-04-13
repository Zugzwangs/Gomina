/*******************************************************/
//
//
/*******************************************************/

#include "cpuplayer.h"

CpuPlayer::CpuPlayer(QObject *parent) : Player(parent)
{
    init();
}

void humanplayer::init()
{
    setName("cpu player");
    setAvatar("avatar_bot.png");
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

void humanplayer::exportProfil(QString profilFile)
{
    // no needed maybe useful for bot crafting?
}

CpuPlayer::~CpuPlayer()
{

}
