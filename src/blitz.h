#ifndef BLITZ_H
#define BLITZ_H

#include <QObject>

class Blitz : public QObject
{
    Q_OBJECT
public:
    explicit Blitz(QObject *parent = 0);
    ~Blitz();

signals:

public slots:
};

#endif // BLITZ_H
