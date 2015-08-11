#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsSceneDragDropEvent>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsItem>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QPainter>
#include <QRectF>
#include <QPen>


class MyItem : public QGraphicsItem
{

public:
    MyItem(double radius);
    ~MyItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    //bool getColorFlag();
    //void setColorFlag(bool flag);

protected:
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    //void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    //virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mouseDoubleClickEvent (QGraphicsSceneMouseEvent *event);
private:

    //QPainter *m_painter;
    //int m_x, m_y;
    double m_radius;

    bool m_colorFlag;//true:blue, flase:black

};

#endif // MYITEM_H
