/*******************************************************/
//
//
/*******************************************************/

#include "graphicshitboxitem.h"

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

graphicsHitboxItem::graphicsHitboxItem(const QRectF &rect, QGraphicsItem* parent) : QGraphicsRectItem(rect, parent)
{
    initialisation();
}

void graphicsHitboxItem::initialisation()
{
    GamePos = QPoint(0, 0);
    // hitbox => keep item invisible
    setPen( Qt::NoPen );
    setBrush( QBrush(Qt::transparent) );

    // set behavior
    setAcceptHoverEvents(true);
    setFlag( QGraphicsItem::ItemIsMovable, false);
    setFlag( QGraphicsItem::ItemIsSelectable, false);
}

void graphicsHitboxItem::​hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
    qDebug() << "graphicsHitboxItem::​hoverEnterEvent()";
    setBrush( QBrush(Qt::blue) );
    QGraphicsRectItem::hoverEnterEvent(event);
}

void graphicsHitboxItem::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
    qDebug() << "graphicsHitboxItem::hoverMoveEvent()";
}

void graphicsHitboxItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
    qDebug() << "graphicsHitboxItem::hoverLeaveEvent()";
    setBrush( QBrush(Qt::transparent) );
    QGraphicsRectItem::hoverLeaveEvent(event);
}

void graphicsHitboxItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    Q_UNUSED(event);
    qDebug() << "MOUSE PRESS EVENT ON HITBOX";
    qDebug() << "HitBoxItemPos x=" << this->pos().x() << " y=" << this->pos().y();
    qDebug() << "HitBoxItemScenePos x=" << this->scenePos().x() << " y=" << this->scenePos().y();
    qDebug() << "GamePos is x=" << GamePos.x() << " y=" << GamePos.y();
    emit clicked(GamePos);
}

void graphicsHitboxItem::setGamePos(QPoint p)
{
    GamePos = p;
}

QPoint graphicsHitboxItem::getGamePos()
{
    return GamePos;
}

graphicsHitboxItem::~graphicsHitboxItem()
{

}

