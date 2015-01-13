#ifndef CPUPLAYER_H
#define CPUPLAYER_H

#include <QObject>

class CpuPlayer : public QObject
{
    Q_OBJECT
public:
    explicit CpuPlayer(QObject *parent = 0);
    ~CpuPlayer();

signals:

public slots:
};

#endif // CPUPLAYER_H
