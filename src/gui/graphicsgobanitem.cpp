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

GraphicsGobanItem::GraphicsGobanItem(int _gobanSize, QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
    // launch the build
    buildGoban(_gobanSize);

    // set behavior
    setAcceptHoverEvents(true);
    setFlag( QGraphicsItem::ItemIsMovable, false);
    setFlag( QGraphicsItem::ItemIsSelectable, false);

    // connections

}

// build all items composing the board
void GraphicsGobanItem::buildGoban(int _gobanSize)
{
    // if goban size is incorrect set it to the default value
    if ( _gobanSize < 1 || _gobanSize > 19)
        goBanSize = 19;
    else
        goBanSize = _gobanSize;

    // compute and set the size of the Goban Item
    GobanWidth  = (goBanSize-1)*GOBAN_STEP_SIZE_WIDTH  + goBanSize*GOBAN_LINE_THICKNESS + 2*GOBAN_BORDER_THICKNESS;
    GobanHeight = (goBanSize-1)*GOBAN_STEP_SIZE_HEIGHT + goBanSize*GOBAN_LINE_THICKNESS + 2*GOBAN_BORDER_THICKNESS;
    this->setRect(0, 0, GobanWidth, GobanHeight);

    // set pen and brush
    setPen( QPen(Qt::NoPen) );
    setBrush( QBrush(QPixmap(":res/Goban_texture_01.jpg")) );

    // build the lines
    for (int i=1; i<=goBanSize; i++)
        {
        buildLine(i, Qt::Vertical);
        buildLine(i, Qt::Horizontal);
        }

    // build hoshi (only in the case of a 19x19 goban)
    if ( goBanSize == 19)
        {
        buildHoshi( QPoint(4,4) );
        buildHoshi( QPoint(10,4) );
        buildHoshi( QPoint(16,4) );
        buildHoshi( QPoint(4,10) );
        buildHoshi( QPoint(10,10) );
        buildHoshi( QPoint(16,10) );
        buildHoshi( QPoint(4,16) );
        buildHoshi( QPoint(10,16) );
        buildHoshi( QPoint(16,16) );
        }

    // build the hitbox
    for (int i=1; i<=goBanSize; i++)
        {
        for (int j=1; j<=goBanSize; j++)
            {
            buildHitbox( QPoint(i, j) );
            }
        }

    // build Letters
    for(int i=1; i<=goBanSize; i++)
        {
        buildLetters(i, Qt::TopEdge);
        buildLetters(i, Qt::BottomEdge);
        buildLetters(i, Qt::LeftEdge);
        buildLetters(i, Qt::RightEdge);
        }
}

// convert a game position to coord in Goban coord
QPointF GraphicsGobanItem::coord2Pos(QPoint p)
{
    float _x_pos = GOBAN_BORDER_THICKNESS + (p.x()-1)*(GOBAN_STEP_SIZE_WIDTH+GOBAN_LINE_THICKNESS) + GOBAN_LINE_THICKNESS/2;
    float _y_pos = GOBAN_BORDER_THICKNESS + (p.y()-1)*(GOBAN_STEP_SIZE_HEIGHT+GOBAN_LINE_THICKNESS)+ GOBAN_LINE_THICKNESS/2;;
    return QPointF(_x_pos, _y_pos);
}

// build the n'th horizontal or vertical line
void GraphicsGobanItem::buildLine(int n, Qt::Orientation orientation)
{
    QPointF curPos = coord2Pos( QPoint(n, n) );
    QPen penLine;
    penLine.setWidth(GOBAN_LINE_THICKNESS);
    penLine.setColor(Qt::black);

    switch (orientation)
        {
        case Qt::Horizontal:
            {
            QGraphicsLineItem*  crtline = new QGraphicsLineItem(GOBAN_BORDER_THICKNESS+GOBAN_LINE_THICKNESS/2, curPos.y(), GobanWidth-GOBAN_BORDER_THICKNESS-GOBAN_LINE_THICKNESS/2, curPos.y(), this);
            crtline->setPen( penLine );
            break;
            }

        case Qt::Vertical:
            {
            QGraphicsLineItem*  crtlineV = new QGraphicsLineItem(curPos.x(), GOBAN_BORDER_THICKNESS+GOBAN_LINE_THICKNESS/2, curPos.x(), GobanHeight-GOBAN_BORDER_THICKNESS-GOBAN_LINE_THICKNESS/2, this);
            crtlineV->setPen( penLine );
            break;
            }

        default:
            qDebug() << "wrong call of the function GraphicsGobanItem::buildLine(int n, Qt::Orientation orientation)";
            break;
        }
}

// build hoshi item at the specified point
void GraphicsGobanItem::buildHoshi(QPoint p)
{
    QRectF hoshi_rect(0, 0, GOBAN_HOSHI_RADIUS, GOBAN_HOSHI_RADIUS);
    hoshi_rect.moveCenter( coord2Pos(p) );
    QGraphicsEllipseItem* hoshi = new QGraphicsEllipseItem(hoshi_rect, this);
    hoshi->setBrush( QBrush(Qt::black, Qt::SolidPattern) );
}

// build a invisible item (Hitbox) to handle clics on case 'p'
void GraphicsGobanItem::buildHitbox(QPoint p)
{
    // build the hitbox
    QRectF yoMan( QPointF(0, 0), QSizeF(STONE_SIZE_WIDTH, STONE_SIZE_WIDTH) );
    yoMan.moveCenter( coord2Pos(p) );
    graphicsHitboxItem* crtCase = new graphicsHitboxItem(yoMan, this);
}

// build Letters and Digits around the board
void GraphicsGobanItem::buildLetters(int n, Qt::Edge edge)
{
QPointF curPos = coord2Pos( QPoint(n, n) );

    switch (edge)
    {
        case Qt::TopEdge:
            {
            QGraphicsTextItem* crtLetterTop = new QGraphicsTextItem(LetterList.at(n-1), this);
            crtLetterTop->setFont(QFont("Arial", 6));
            crtLetterTop->setPos(curPos.x() - crtLetterTop->boundingRect().width()/2, 0);
            break;
            }

        case Qt::BottomEdge:
            {
            QGraphicsTextItem* crtLetterDown = new QGraphicsTextItem(LetterList.at(n-1), this);
            crtLetterDown->setFont(QFont("Arial", 6));
            crtLetterDown->setPos(curPos.x() - crtLetterDown->boundingRect().width()/2, GobanHeight-crtLetterDown->boundingRect().height());
            break;
            }

        case Qt::LeftEdge:
            {
            QGraphicsTextItem* crtNumberLeft = new QGraphicsTextItem(NumberList.at(goBanSize - (n)), this);
            crtNumberLeft->setFont(QFont("Arial", 6));
            crtNumberLeft->setPos(0, curPos.y() - crtNumberLeft->boundingRect().height()/2);
            break;
            }

        case Qt::RightEdge:
            {
            QGraphicsTextItem* crtNumberRight = new QGraphicsTextItem(NumberList.at(goBanSize - (n)), this);
            crtNumberRight->setFont(QFont("Arial", 6));
            crtNumberRight->setPos(GobanWidth-crtNumberRight->boundingRect().width(), curPos.y() - crtNumberRight->boundingRect().height()/2);
            break;
            }

        default:
            break;
    }
}

void GraphicsGobanItem::​hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
    qDebug() << "GraphicsGobanItem::​hoverEnterEvent()";
    //event->ignore();
}

void GraphicsGobanItem::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
    qDebug() << "GraphicsGobanItem::hoverMoveEvent()";
    //event->ignore();
}

void GraphicsGobanItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
    qDebug() << "GraphicsGobanItem::hoverLeaveEvent()";
}

GraphicsGobanItem::~GraphicsGobanItem()
{

}

