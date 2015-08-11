#include "myitem.h"
#include <QMimeData>
#include <QDrag>
#include <QDebug>
#include <QGraphicsView>
#include <QVarLengthArray>
#include <QPointF>

MyItem::MyItem(double radius)
{
    m_colorFlag = true;
    m_radius = radius;
    setFlags(ItemIsSelectable | ItemIsMovable);
    //setAcceptsHoverEvents(true);
    //setAcceptDrops(true);

}

MyItem::~MyItem()
{

}

QRectF MyItem::boundingRect() const
{
    qreal adjust=0.5;
    return QRectF(-100-m_radius-adjust,-100-m_radius-adjust,
                  2*m_radius+adjust,2*m_radius+adjust);

}

void MyItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    //painter->drawRect(0, 0, 50, 50);
    //painter->setPen(QPen(Qt::green, 1));
    //painter->setBrush(Qt::blue);
    //qDebug()<<"paint...............";

    if(m_colorFlag)
        painter->setBrush(Qt::blue);
    else
        painter->setBrush(Qt::black);

    painter->drawEllipse(QPointF(-100, -100), m_radius, m_radius);

    //painter->fillRect(QRectF(-25, -25, 50, 50), Qt::blue);
    //painter->setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //painter->setBrush(Qt::NoBrush);

}
/*
bool MyItem::getColorFlag()
{
    return m_colorFlag;
}

void MyItem::setColorFlag(bool flag)
{
    m_colorFlag = flag;
}
*/

/*
void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //m_colorFlag = !m_colorFlag;
    //update();
    QGraphicsItem::mousePressEvent(event);

}
*/

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    double x = this->pos().x();
    double y = this->pos().y();

    //qDebug()<<"this.x="<<x<<" ,this.y="<<y;
    //qDebug()<<"mouse.x="<<event->pos().x()<<", mouse.y="<<event->pos().y();

    QGraphicsItem::mouseMoveEvent(event);

}


void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    double x = this->pos().x();

    double y = this->pos().y();
/*
    if(y<26)
        y = 26;
    else if(y>174)
        y = 174;
    if(x<27)
        x = 26;
    else if(x>174)
        x = 174;
*/
    double s = (x - 100)*(x - 100) + (y - 100)*(y - 100);
    //qDebug()<<"this.x="<<x<<" ,this.y="<<y;
    qDebug()<<"s= "<<s;
    qDebug()<<"Release";

    if(s>76*76)
    {

       if(y<100)
           y = y + 10;
       else
           y = y - 10;
       if(x<100)
           x = x + 10;
       else
           x = x - 10;

       if(y<26)
           y = 26;
       else if(y>174)
           y = 174;
       if(x<27)
           x = 26;
       else if(x>174)
           x = 174;

       this->setPos(x, y);
       qDebug()<<"set.x="<<x<<" ,set.y="<<y;
       update();
       return;
     }

     QGraphicsItem::mouseReleaseEvent(event);
}

/*
void MyItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<<"drag enter";
    QGraphicsItem::dragEnterEvent(event);
}
*/

void MyItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_colorFlag)
        m_colorFlag = false;
    else
       m_colorFlag = true;
    //qDebug()<<"flag = "<<m_colorFlag;
    QGraphicsItem::mouseDoubleClickEvent(event);
    update();
}

/*
QVariant MyItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    qDebug()<<"change";
    if(y<26)
        y = 26;
    else if(y>174)
        y = 174;
    if(x<27)
        x = 26;
    else if(x>174)
        x = 174;
    if (change == ItemPositionChange )
    {
        // value is the new position.
        QPointF newPos = value.toPointF();
        QRectF rect = scene()->sceneRect();
        if (!rect.contains(newPos))
        {
            // Keep the item inside the scene rect.
            newPos.setX(x);
            newPos.setY(y);
            qDebug()<<"new              .x="<<newPos.x()<<" ,new              .y="<<newPos.y();
            return newPos;
        }
    }
    return QGraphicsItem::itemChange(change, value);
}
*/

