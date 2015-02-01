/*******************************************************/
//
//
/*******************************************************/

#ifndef GRAPHICSHITBOXITEM_H
#define GRAPHICSHITBOXITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneHoverEvent>

class graphicsHitboxItem : public QGraphicsRectItem
{
public:
    graphicsHitboxItem(QGraphicsItem * parent = 0);
    graphicsHitboxItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = 0);
    graphicsHitboxItem(const QRectF &rect, QGraphicsItem* parent = 0);
    ~graphicsHitboxItem();

protected:
    virtual void ​hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);

private:
    void initialisation();
};

#endif // GRAPHICSHITBOXITEM_H
