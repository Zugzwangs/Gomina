/*******************************************************/
//
//
/*******************************************************/
#include <QDebug>
#include "goban.h"

Goban::Goban(QObject *parent) : QObject(parent)
{
    setSize(QSize(19, 19));
}

int Goban::getHeight()
{
    return size.height();
}

int Goban::getWidth()
{
    return size.width();
}

QSize Goban::getSize()
{
    return size;
}

void Goban::setSize(QSize s)
{
    grid.resize(s.width()*s.height());
    size.setWidth( s.width() );
    size.setHeight( s.height() );
    grid.fill(-1);
}

int Goban::getValue(int x, int y)
{
    return grid.at( (x-1)+(y-1)*size.width() );
}

int Goban::getValue(QPoint p)
{
    qDebug() << "###############################";
    qDebug() << "getValue ON (" << p.x() << ";" << p.y() << ")";
    qDebug() << "computed case is " << p.x()+p.y()*size.width();
    qDebug() << "###############################";
    return grid.at( (p.x()-1)+(p.y()-1)*size.width() );
}

void Goban::setValue(QPoint p, int v)
{
    grid[ (p.x()-1)+(p.y()-1)*size.height() ] = v;
}

Goban::~Goban()
{

}

