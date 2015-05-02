/*******************************************************/
//
//
/*******************************************************/

#include "player.h"
#include <QtMath>

Player::Player(QObject *parent) : QObject(parent)
{

}

void Player::loadProfil(QString profilFile) {}
void Player::exportProfil() {}

void Player::setName(QString _name)
{
    this->name = _name;
}

void Player::setAvatar(QString _avatar)
{
    this->avatar = _avatar;
}

void Player::setElo(int val)
{
    this->elo = val;
}

int Player::getRank()
{
    return( (int)floor(elo/100.0) );
}

void Player::setLoc(Location _loc)
{
    playFrom = _loc;
}

void Player::setStatus(Status _stat)
{
    stat = _stat;
}

void Player::setSide(Side _side)
{
    camp = _side;
}

Player::~Player()
{

}
