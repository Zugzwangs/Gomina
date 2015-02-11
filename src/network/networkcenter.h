/*******************************************************/
//
//
/*******************************************************/

#ifndef NETWORKCENTER_H
#define NETWORKCENTER_H

#include <QObject>

class NetworkCenter : public QObject
{
    Q_OBJECT
public:
    explicit NetworkCenter(QObject *parent = 0);
    ~NetworkCenter();

signals:

public slots:
};

#endif // NETWORKCENTER_H
