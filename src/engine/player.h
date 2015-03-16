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
    explicit Player(QObject *parent = 0);
    virtual void init(Location Loc) = 0;
    ~Player();

    enum Location { Gui = 0, Network = 1, Brain = 2 };
    enum Status { Active = 0, Defend = 1, Spectate = 2, Wait = 3 };
    enum Side { Black = 0, White = 1, NoSide = 2 };

    void setName(QString _name);
    void setAvatar(QString _avatar);
    void setStatus(Status _stat);
    void setRole(Side _side);

private:
    QString name;
    QString avatar;
    int rank;
    int elo;
    Status stat;
    Location playFrom;
    Side role;

signals:
    void loaded();

};

#endif // PLAYER_H
