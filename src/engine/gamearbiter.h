/*******************************************************/
//
//
/*******************************************************/

#ifndef GAMEARBITER_H
#define GAMEARBITER_H

#include <QObject>

class GameArbiter : public QObject
{
    Q_OBJECT
public:
    explicit GameArbiter(QObject *parent = 0);
    ~GameArbiter();

signals:

public slots:
};

#endif // GAMEARBITER_H
