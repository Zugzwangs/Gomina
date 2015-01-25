/*******************************************************/
//
//
/*******************************************************/

#include "graphicsgobanitem.h"
#include "graphicshitboxitem.h"

#include <QPen>
#include <QDebug>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>

GraphicsGobanItem::GraphicsGobanItem(int gobanSize, QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
    // compute the size of the board
    GobanWidth  = (gobanSize-1) * (GOBAN_STEP_SIZE_WIDTH + GOBAN_LINE_THICKNESS) + 2*GOBAN_BORDER_THICKNESS;
    GobanHeight = (gobanSize-1) * (GOBAN_STEP_SIZE_HEIGHT+ GOBAN_LINE_THICKNESS) + 2*GOBAN_BORDER_THICKNESS;
    setRect(0, 0, GobanWidth, GobanHeight);

    // set pen and brush
    setPen( QPen(Qt::white) );
    setBrush( QBrush(QPixmap(":res/Goban_texture_01.jpg")) );

    // build the lines
    int computedPosV=0;
    int computedPosH=0;
    for (int i=0; i<gobanSize; i++)
        {
        QPen penLine;
        penLine.setWidth(GOBAN_LINE_THICKNESS);
        penLine.setColor(Qt::black);

        // horizontal lines
        computedPosV = GOBAN_BORDER_THICKNESS + i*(GOBAN_STEP_SIZE_HEIGHT+GOBAN_LINE_THICKNESS);
        QGraphicsLineItem*  crtlineH = new QGraphicsLineItem(GOBAN_BORDER_THICKNESS, computedPosV, GobanWidth-GOBAN_BORDER_THICKNESS, computedPosV, this);
        crtlineH->setPen( penLine );

        // verticals lines
        computedPosH = GOBAN_BORDER_THICKNESS + i*(GOBAN_STEP_SIZE_WIDTH+GOBAN_LINE_THICKNESS);
        QGraphicsLineItem*  crtlineV = new QGraphicsLineItem(computedPosH, GOBAN_BORDER_THICKNESS, computedPosH, GobanHeight-GOBAN_BORDER_THICKNESS, this);
        crtlineV->setPen( penLine );
        }

    // build the hoshi (only in the case of a 19x19 goban)

    if ( gobanSize == 19)
        {
        //create an hoshi at case P(x,y):
        int _x = 3;
        int _y = 3;
        int _x_pos = GOBAN_BORDER_THICKNESS + _x*(GOBAN_STEP_SIZE_WIDTH+GOBAN_LINE_THICKNESS) - GOBAN_HOSHI_RADIUS/2 - GOBAN_LINE_THICKNESS/2;
        int _y_pos = GOBAN_BORDER_THICKNESS + _y*(GOBAN_STEP_SIZE_HEIGHT+GOBAN_LINE_THICKNESS) - GOBAN_HOSHI_RADIUS/2;
        QRectF hoshi_rect(_x_pos, _y_pos, GOBAN_HOSHI_RADIUS, GOBAN_HOSHI_RADIUS);
        hoshi_rect.moveCenter();
        QGraphicsEllipseItem* hoshi = new QGraphicsEllipseItem(hoshi_rect, this);
        hoshi->setBrush( QBrush(Qt::black, Qt::SolidPattern) );
        }

    // build the hitbox
    int tempX, tempY;
    for (int i=0; i<gobanSize; i++)
        {
        for (int j=0; j<gobanSize; j++)
            {
            tempX = GOBAN_BORDER_THICKNESS + i*GOBAN_STEP_SIZE_WIDTH  + i*GOBAN_LINE_THICKNESS - GOBAN_STEP_SIZE_WIDTH/2;
            tempY = GOBAN_BORDER_THICKNESS + j*GOBAN_STEP_SIZE_HEIGHT + j*GOBAN_LINE_THICKNESS - GOBAN_STEP_SIZE_HEIGHT/2;
            graphicsHitboxItem* crtCase = new graphicsHitboxItem(tempX, tempY, STONE_SIZE_WIDTH, STONE_SIZE_HEIGHT, this);
            }
        }

    // set behavior
    setAcceptHoverEvents(true);
    setFlag( QGraphicsItem::ItemIsMovable, false);
    setFlag( QGraphicsItem::ItemIsSelectable, false);
}

QPoint GraphicsGobanItem::coord2Pos(QPoint p)
{

}

void GraphicsGobanItem::​hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
    qDebug() << "GraphicsGobanItem::​hoverEnterEvent()";
    //event->ignore();
}

void GraphicsGobanItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
    qDebug() << "GraphicsGobanItem::hoverLeaveEvent()";
}

GraphicsGobanItem::~GraphicsGobanItem()
{

}

