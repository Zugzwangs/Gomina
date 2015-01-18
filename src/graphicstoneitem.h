#ifndef GRAPHICSTONEITEM_H
#define GRAPHICSTONEITEM_H

#include <QGraphicsEllipseItem>

class GraphicStoneITem : public QGraphicsPixmapItem
{
public:
    GraphicStoneITem(QGraphicsItem * parent = 0);
    GraphicStoneITem(int camp, QGraphicsItem * parent = 0);
    ~GraphicStoneITem();
};

#endif // GRAPHICSTONEITEM_H
