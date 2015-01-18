#ifndef GRAPHICSGOBANITEM_H
#define GRAPHICSGOBANITEM_H

#include <QGraphicsRectItem>

class GraphicsGobanItem : public QGraphicsRectItem
{

public:

    static const uint GOBAN_STEP_SIZE=40;
    static const uint GOBAN_BORDER_THICKNESS=30;

    GraphicsGobanItem(int gobanSize, QGraphicsItem *parent=0);
    ~GraphicsGobanItem();

private:
    uint GobanWidth;
    uint GobanHeight;
};

#endif // GRAPHICSGOBANITEM_H
