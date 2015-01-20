/*******************************************************/
//
//
/*******************************************************/

#ifndef GOBAN_H
#define GOBAN_H

#include <QObject>
#include <QSize>
#include <QPoint>

class Goban : public QObject
{
    Q_OBJECT

public:
    explicit Goban(QObject *parent = 0);
    ~Goban();
    int getHeight();
    int getWidth();
    QSize getSize();
    int getValue(int x, int y);
    int getValue(QPoint p);

private:
    QSize size;


signals:
    void changed();

public slots:

};

#endif // GOBAN_H
