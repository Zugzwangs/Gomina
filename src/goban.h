/*******************************************************/
//
//
/*******************************************************/

#ifndef GOBAN_H
#define GOBAN_H

#include <QObject>

class Goban : public QObject
{
    Q_OBJECT

public:
    explicit Goban(QObject *parent = 0);
    ~Goban();

private:
    //choose the right data's structure

signals:

public slots:

};

#endif // GOBAN_H
