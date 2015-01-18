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
    ~GobanView();
};

#endif // GOBANVIEW_H
