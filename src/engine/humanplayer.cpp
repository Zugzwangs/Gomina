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
    // minimal state of a huma player instance.
    setName("Unnamed Player");
    setAvatar("avatar.png");
    setElo(1000);
    setLoc(Gui);
    setStatus(Spectate);
    setSide(NoSide);
}

// go to the file 'profileFile' located into the local 'player' or 'data' folder
// and load data from it (xml)
void humanplayer::loadProfil(QString profilFile)
{
    // check if file exist and read it
    if ( false )
        {
        //set this with values
        }
    else
        {
        // set a default profile
        setName("Unnamed Player");
        setAvatar("avatar.png");
        setElo(1000);
        }
    emit profilLoaded();
}

// write player data from this instance
// to profilFile (.xml)
void humanplayer::exportProfil(QString profilFile)
{

}

humanplayer::~humanplayer()
{

}
