/*******************************************************/
//
//
/*******************************************************/

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
    grid.fill(0);
}

int Goban::getValue(int x, int y)
{
    return grid.at( x+y*size.width() );
}

int Goban::getValue(QPoint p)
{
    return grid.at( p.x()+p.y()*size.width() );
}

void Goban::setValue(QPoint p, int v)
{
    grid[ p.x()+p.y()*size.height() ] = v;
}

Goban::~Goban()
{

}

