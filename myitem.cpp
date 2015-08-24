#include "myitem.h"
#include <QMimeData>
#include <QDrag>
#include <QDebug>
#include <QGraphicsView>
#include <QVarLengthArray>
#include <QPointF>
#include "math.h"

MyItem::MyItem(double radius, double Radius)
{
    m_colorFlag = true;
    m_radius = radius;
    m_Radius = Radius;
    setFlags(ItemIsSelectable | ItemIsMovable);
}

MyItem::~MyItem()
{

}

QRectF MyItem::boundingRect() const
{
    return QRectF(-m_radius, -m_radius,
                  2*m_radius, 2*m_radius);
}

void MyItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    if(m_colorFlag)
        painter->setBrush(Qt::blue);
    else
        painter->setBrush(Qt::red);

    painter->drawEllipse(QPointF(0, 0), m_radius, m_radius);

}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qreal x = pos().x();
    qreal y = pos().y();
    double D = m_Radius - m_radius - 2;

    // limit circle position
    if(x*x + y*y >D*D)
    {
        double tmpX = x*D/sqrt(x*x + y*y);
        double tmpY = y*D/sqrt(x*x + y*y);

        setPos(tmpX, tmpY);
    }

    QGraphicsItem::mouseReleaseEvent(event);
}

void MyItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    m_colorFlag = !m_colorFlag;
    QGraphicsItem::mouseDoubleClickEvent(event);
    update();
}
