/*******************************************************/
//
//
/*******************************************************/

#include "player.h"
#include <QtMath>

Player::Player(QObject *parent) : QObject(parent)
{

}

//set or reset profil to consistant empty profil
Player::init()
{

}

void Player::loadProfil(QString profilFile)
{
// check if file exist and read it
// set this with values
emit profilLoaded();
}

void Player::setName(QString _name)
{
    this->name = _name;
}

void Player::setAvatar(QString _avatar)
{
    this->avatar = _avatar;
}

int Player::getRank()
{
    return(elo);
}

void Player::setElo(int val)
{
    this->elo = qFloor(val/100);
}

void Player::setStatus(Status _stat)
{
    stat = _stat;
}

void Player::setRole(Side _side)
{
    role = _side;
}

void Player::setLoc(Location _loc)
{

}

Player::~Player()
{

}
