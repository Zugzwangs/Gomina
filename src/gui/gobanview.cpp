/*******************************************************/
// Subclass of QGraphicsView who implement drag'n drop,
// context menu ...
//
/*******************************************************/

#include "gobanview.h"
#include <QDebug>

GobanView::GobanView(QWidget *parent) : QGraphicsView(parent)
{
    // rendering options
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    //

    // setting background picture
    setBackgroundBrush( QBrush(QPixmap(":res/goban_background.jpg")) );
}

// adjust the zoom factor to make Goban item take 80% of the View's width
void GobanView::adjustZoom()
{
    this->fitInView( scene()->sceneRect(), Qt::KeepAspectRatio );
}

void GobanView::resizeEvent(QResizeEvent * event)
{
    QGraphicsView::resizeEvent(event);
    adjustZoom();
}

GobanView::~GobanView()
{

}

