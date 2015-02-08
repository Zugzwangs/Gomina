/*******************************************************/
// Subclass of QGraphicsView who implement drag'n drop,
// context menu ...
//
/*******************************************************/

#include "gobanview.h"

GobanView::GobanView(QWidget *parent) : QGraphicsView(parent)
{
    this->setBackgroundBrush( QBrush(QPixmap(":res/goban_background.jpg")) );
}

// adjust the zoom factor to make Goban item take 80% of the View's width
void GobanView::scaleView(qreal scaleFactor)
{
    qreal factor = matrix().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor<0.1 || factor>1.1)
        return;
    scale(scaleFactor, scaleFactor);
}

GobanView::~GobanView()
{

}

