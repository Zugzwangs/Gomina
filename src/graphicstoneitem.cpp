/*******************************************************/
//
//
/*******************************************************/

#include "graphicstoneitem.h"
#include "graphicsgobanitem.h"


GraphicStoneITem::GraphicStoneITem(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{

}

GraphicStoneITem::GraphicStoneITem(int camp, QGraphicsItem * parent) : QGraphicsPixmapItem(parent)
{

    //GraphicsGobanItem.GOBAN_STEP_SIZE;

    switch (camp)
        {
        case 0:
            {
            setPixmap( QPixmap(":res/black_stone.png") );
            break;
            }

        case 1:
            {
            setPixmap( QPixmap(":res/white_stone.png") );
            break;
            }

        default:
        break;
        }
}

GraphicStoneITem::~GraphicStoneITem()
{

}

