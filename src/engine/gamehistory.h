/*******************************************************/
//
//
/*******************************************************/

#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QObject>

class GameHistory : public QObject
{
    Q_OBJECT
public:
    explicit GameHistory(QObject *parent = 0);
    ~GameHistory();

signals:

public slots:
};

#endif // GAMEHISTORY_H
