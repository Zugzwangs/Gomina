/*******************************************************/
//
//
/*******************************************************/

#include "graphicstoneitem.h"
#include "graphicsgobanitem.h"


GraphicStoneITem::GraphicStoneITem(int camp, QGraphicsItem * parent) : QGraphicsPixmapItem(parent)
{
    int _sizeW = GraphicsGobanItem::STONE_SIZE_WIDTH;
    int _sizeH = GraphicsGobanItem::STONE_SIZE_HEIGHT;

    switch (camp)
        {
        case 0:
            {          
            setPixmap( QPixmap(":res/black_stone.png").scaled(_sizeW, _sizeH, Qt::KeepAspectRatio, Qt::SmoothTransformation) );
            break;
            }

        case 1:
            {
            setPixmap( QPixmap(":res/white_stone.png").scaled(_sizeW, _sizeH, Qt::KeepAspectRatio, Qt::SmoothTransformation) );
            break;
            }

        default:
            {
            setPixmap( QPixmap(":res/white_stone.png").scaled(_sizeW, _sizeH, Qt::KeepAspectRatio, Qt::SmoothTransformation) );
            break;
            }
        break;
        }
}

GraphicStoneITem::~GraphicStoneITem()
{

}

