/*******************************************************/
//
//
/*******************************************************/

#include "graphicshitboxitem.h"
#include "graphicstoneitem.h"

#include <QPen>
#include <QDebug>

graphicsHitboxItem::graphicsHitboxItem(QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
    initialisation();
}

graphicsHitboxItem::graphicsHitboxItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent) : 	QGraphicsRectItem(x, y, width, height, parent)
{
    initialisation();
}

void graphicsHitboxItem::initialisation()
{
    // hitbox => keep item invisible
    setPen( Qt::NoPen );
    setBrush( QBrush(Qt::yellow /*transparent*/) );
    // set behavior
    setAcceptHoverEvents(true);
    setFlag( QGraphicsItem::ItemIsMovable, false);
    setFlag( QGraphicsItem::ItemIsSelectable, false);
}

void graphicsHitboxItem::​hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
    qDebug() << "ENTER FUCK";
    setBrush( QBrush(Qt::blue) );
    QGraphicsRectItem::hoverEnterEvent(event);
}

void graphicsHitboxItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
    qDebug() << "LEAVE FUCK";
    setBrush( QBrush(Qt::transparent) );
    QGraphicsRectItem::hoverLeaveEvent(event);
}

void graphicsHitboxItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    qDebug() << "MOUSE PRESS EVENT ON HITBOX";
    GraphicStoneITem* shit = new GraphicStoneITem(0, this);

}

graphicsHitboxItem::~graphicsHitboxItem()
{

}

