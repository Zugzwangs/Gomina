/*******************************************************/
//
//
/*******************************************************/

#ifndef GRAPHICSHITBOXITEM_H
#define GRAPHICSHITBOXITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneHoverEvent>

class graphicsHitboxItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    graphicsHitboxItem(QGraphicsItem * parent = 0);
    graphicsHitboxItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = 0);
    graphicsHitboxItem(const QRectF &rect, QGraphicsItem* parent = 0);
    ~graphicsHitboxItem();
    void setGamePos(QPoint p);
    QPoint getGamePos();

protected:
    virtual void ​hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent* event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);

private:
    void initialisation();
    QPoint GamePos;

signals:
    void clicked(QPoint p);

};

#endif // GRAPHICSHITBOXITEM_H
