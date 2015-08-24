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
    MyItem(double radius, double Radius);
    ~MyItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent (QGraphicsSceneMouseEvent *event);

private:
    double m_radius;
    double m_Radius;

    bool m_colorFlag;//true:red, flase:black

};

#endif // MYITEM_H
