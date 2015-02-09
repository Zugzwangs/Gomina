/*******************************************************/
//
//
/*******************************************************/

#ifndef GOBAN_H
#define GOBAN_H

#include <QObject>
#include <QSize>
#include <QPoint>
#include <QVector>

class Goban : public QObject
{
    Q_OBJECT

public:
    explicit Goban(QObject *parent = 0);
    ~Goban();
    int getHeight();
    int getWidth();
    QSize getSize();
    void setSize(QSize s);
    int getValue(int x, int y);
    int getValue(QPoint p);
    void setValue(QPoint p, int v);

private:
    QSize size;
    QVector<int> grid;

signals:
    void changed();

public slots:

};

#endif // GOBAN_H
