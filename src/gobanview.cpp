/*******************************************************/
// Subclass of QGraphicsView who implement drag'n drop,
// context menu ...
//
/*******************************************************/

#include "gobanview.h"

GobanView::GobanView(QWidget *parent) : QGraphicsView(parent)
{
    this->setBackgroundBrush( QBrush(Qt::yellow) );
}

GobanView::~GobanView()
{

}

