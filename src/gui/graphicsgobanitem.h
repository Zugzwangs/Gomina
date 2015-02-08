/*******************************************************/
//
//
/*******************************************************/

#ifndef GRAPHICSGOBANITEM_H
#define GRAPHICSGOBANITEM_H

#include <QObject>
#include <QGraphicsRectItem>

class GraphicsGobanItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    static const uint STONE_SIZE_HEIGHT = 20;
    static const uint STONE_SIZE_WIDTH  = 20;
    static const uint GOBAN_STEP_SIZE_HEIGHT = 24;
    static const uint GOBAN_STEP_SIZE_WIDTH  = 22;  //un goban tradi est légérement rectangulaire
    static const uint GOBAN_LINE_THICKNESS = 2;
    static const uint GOBAN_BORDER_THICKNESS = 35;
    static const uint GOBAN_LEGEND_BOX = 20;
    static const uint GOBAN_HOSHI_RADIUS = 6;

    GraphicsGobanItem(int gobanSize, QGraphicsItem *parent=0);
    ~GraphicsGobanItem();
    QPointF coord2Pos(QPoint p);
    //setGobanTexture(QString s);

protected:
    virtual void ​hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent* event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

private:
    static QStringList LetterList;
    static QStringList NumberList;
    //static QList<QPoint> HoshiPosList;

    uint GobanWidth;
    uint GobanHeight;
    int goBanSize;

    void buildGoban(int _gobanSize);
    void buildHoshi(QPoint p);
    void buildHitbox(QPoint p);
    void buildLine(int n, Qt::Orientation orientation);
    void buildLetters(int n, Qt::Edge edge);

public slots:
    void playOnCase(QPoint p, int camp);

signals:
    void clickOnCase(QPoint p);

};

#endif // GRAPHICSGOBANITEM_H
