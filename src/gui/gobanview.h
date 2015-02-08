/*******************************************************/
//
//
/*******************************************************/

#ifndef GOBANVIEW_H
#define GOBANVIEW_H

#include <QGraphicsView>

class GobanView : public QGraphicsView
{
    Q_OBJECT

public:
    GobanView(QWidget *parent = 0);
    void scaleView(qreal scaleFactor);
    ~GobanView();
};

#endif // GOBANVIEW_H
