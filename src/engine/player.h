/*******************************************************/
//
//
/*******************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject
{
    Q_OBJECT
    Q_ENUMS(Location)
    Q_ENUMS(Status)
    Q_ENUMS(Side)

public:
    enum Location { Gui = 0, Network = 1, Brain = 2 };
    enum Status { Active = 0, Defend = 1, Spectate = 2, Wait = 3 };
    enum Side { Black = 0, White = 1, NoSide = 2 };

public:
    Player(QObject *parent = 0);
    ~Player();

    virtual void init() = 0;
    virtual void loadProfil(QString profilFile);
    virtual void exportProfil();

    void setName(QString _name);
    void setAvatar(QString _avatar);
    void setElo(int val);
    int getRank();

    void setLoc(Location _loc);
    void setStatus(Status _stat);
    void setSide(Side _side);

private:
    QString name;
    QString avatar;
    int elo;
    Status stat;
    Location playFrom;
    Side camp;

signals:
    void profilLoaded();
    void statusChanged(Status st);
    void profilChanged(QString);

};

#endif // PLAYER_H
