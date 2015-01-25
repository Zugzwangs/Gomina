/*******************************************************/
//
//
/*******************************************************/

#ifndef GRAPHICSGOBANITEM_H
#define GRAPHICSGOBANITEM_H

#include <QGraphicsRectItem>

class GraphicsGobanItem : public QGraphicsRectItem
{

public:
    static const uint STONE_SIZE_HEIGHT = 20;
    static const uint STONE_SIZE_WIDTH  = 20;
    static const uint GOBAN_STEP_SIZE_HEIGHT = 24;
    static const uint GOBAN_STEP_SIZE_WIDTH  = 22;  //un goban tradi est légérement rectangulaire
    static const uint GOBAN_LINE_THICKNESS = 2;
    static const uint GOBAN_BORDER_THICKNESS = 35;
    static const uint GOBAN_LEGEND_BOX = 20;
    static const uint GOBAN_HOSHI_RADIUS = 6;

    GraphicsGobanItem(int gobanSize, QGraphicsItem *parent=0);
    ~GraphicsGobanItem();

protected:
    virtual void ​hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

private:
    uint GobanWidth;
    uint GobanHeight;
    QPoint coord2Pos(QPoint p);
};

#endif // GRAPHICSGOBANITEM_H
