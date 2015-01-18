#include "graphicsgobanitem.h"
#include "graphicshitboxitem.h"

#include <QPen>
#include <QGraphicsLineItem>

GraphicsGobanItem::GraphicsGobanItem(int gobanSize, QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
    // compute the size of the board
    GobanWidth  = (gobanSize-1)*GOBAN_STEP_SIZE + 2*GOBAN_BORDER_THICKNESS;
    GobanHeight = (gobanSize-1)*GOBAN_STEP_SIZE + 2*GOBAN_BORDER_THICKNESS;
    setRect(0, 0, GobanWidth, GobanHeight);

    // set pen and brush
    setPen( QPen(Qt::red) );
    setBrush( QBrush(QPixmap(":/res/texture - Goban.jpg")) );

    // build the lines
    int temp=0;
    for (int i=0; i<gobanSize; i++)
        {
        QPen penLine;
        penLine.setWidth(3);

        temp = GOBAN_BORDER_THICKNESS + i*GOBAN_STEP_SIZE;
        // horizontal lines
        QGraphicsLineItem*  crtlineH = new QGraphicsLineItem(GOBAN_BORDER_THICKNESS, temp, GobanWidth-GOBAN_BORDER_THICKNESS, temp, this);
        crtlineH->setPen( penLine );
        // verticals lines
        QGraphicsLineItem*  crtlineV = new QGraphicsLineItem(temp, GOBAN_BORDER_THICKNESS, temp, GobanHeight-GOBAN_BORDER_THICKNESS, this);
        crtlineV->setPen( penLine );
        }

    // build the hitbox
    int tempX, tempY;
    for (int i=0; i<gobanSize; i++)
        {
        for (int j=0; j<gobanSize; j++)
            {
            tempX = GOBAN_BORDER_THICKNESS + i*GOBAN_STEP_SIZE - GOBAN_STEP_SIZE/2;
            tempY = GOBAN_BORDER_THICKNESS + j*GOBAN_STEP_SIZE - GOBAN_STEP_SIZE/2;
            graphicsHitboxItem* crtCase = new graphicsHitboxItem(tempX, tempY, GOBAN_STEP_SIZE-5, GOBAN_STEP_SIZE-5, this);
            }
        }

    // set behavior
    setAcceptHoverEvents(false);
    setFlag( QGraphicsItem::ItemIsMovable, false);
    setFlag( QGraphicsItem::ItemIsSelectable, false);
}

GraphicsGobanItem::~GraphicsGobanItem()
{

}

