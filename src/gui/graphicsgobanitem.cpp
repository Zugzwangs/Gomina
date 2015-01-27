/*******************************************************/
//
//
/*******************************************************/

#include "graphicsgobanitem.h"
#include "graphicshitboxitem.h"

#include <QPen>
#include <QFont>
#include <QDebug>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>

QStringList GraphicsGobanItem::LetterList = QStringList() << "A" << "B" << "C" << "D" << "E" << "F" << "G" << "H" << "J" << "K" << "L" << "M" << "N" << "O" << "P" << "Q" << "R" << "S" << "T";
QStringList GraphicsGobanItem::NumberList = QStringList() << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11" << "12" << "13" << "14" << "15" << "16" << "17" << "18" << "19";

GraphicsGobanItem::GraphicsGobanItem(int gobanSize, QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
    // if goban size is incorrect set it to the default value
    if ( gobanSize < 1 || gobanSize > 19)
        gobanSize = 19;

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
        QRectF hoshi_rect(0, 0, GOBAN_HOSHI_RADIUS, GOBAN_HOSHI_RADIUS);
        hoshi_rect.moveCenter( coord2Pos(QPoint(3, 3)) );
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

    // build Letters
    for(int i=0; i<gobanSize; i++)
        {
        tempX = GOBAN_BORDER_THICKNESS + i*GOBAN_STEP_SIZE_WIDTH  + i*GOBAN_LINE_THICKNESS;
        tempY = GOBAN_BORDER_THICKNESS + i*GOBAN_STEP_SIZE_HEIGHT + i*GOBAN_LINE_THICKNESS;
        QGraphicsTextItem* crtLetterTop = new QGraphicsTextItem(LetterList.at(i), this);
        QGraphicsTextItem* crtLetterDown = new QGraphicsTextItem(LetterList.at(i), this);
        QGraphicsTextItem* crtNumberLeft = new QGraphicsTextItem(NumberList.at(i), this);
        QGraphicsTextItem* crtNumberRight = new QGraphicsTextItem(NumberList.at(i), this);
        crtLetterTop->setFont(QFont("Arial", 6));
        crtLetterTop->setPos(tempX - crtLetterTop->boundingRect().width()/2, 0);
        crtLetterDown->setFont(QFont("Arial", 6));
        crtLetterDown->setPos(tempX - crtLetterDown->boundingRect().width()/2, GobanHeight-crtLetterDown->boundingRect().width());
        crtNumberLeft->setFont(QFont("Arial", 6));
        crtNumberLeft->setPos(0, tempY - crtNumberLeft->boundingRect().height()/2);
        crtNumberRight->setFont(QFont("Arial", 6));
        crtNumberRight->setPos(GobanWidth-crtNumberRight->boundingRect().width(), tempY - crtNumberRight->boundingRect().height()/2);
        }

    // set behavior
    setAcceptHoverEvents(true);
    setFlag( QGraphicsItem::ItemIsMovable, false);
    setFlag( QGraphicsItem::ItemIsSelectable, false);
}

// convert a game position to coord in Goban coord
QPointF GraphicsGobanItem::coord2Pos(QPoint p)
{
    int _x_pos = GOBAN_BORDER_THICKNESS + p.x()*(GOBAN_STEP_SIZE_WIDTH+GOBAN_LINE_THICKNESS);
    int _y_pos = GOBAN_BORDER_THICKNESS + p.y()*(GOBAN_STEP_SIZE_HEIGHT+GOBAN_LINE_THICKNESS);
    return QPointF(_x_pos, _y_pos);
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

