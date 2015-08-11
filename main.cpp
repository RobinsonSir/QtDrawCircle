#include <QtGui/QApplication>
#include "mainwindow.h"
#include "myitem.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QRadialGradient>
#include <QGraphicsEllipseItem>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    
/*
    QGraphicsScene scene;
    //scene.addText("Hello, world!");
    QGraphicsEllipseItem *e;
    e = new QGraphicsEllipseItem();
    e->setRect(0, 0, 50, 50);
    //QPainter mPainter;
    //mPainter.setPen();
    //e->paint(&mPainter);



    scene.addItem(e);
    e->show();

    QGraphicsView view(&scene);


    // a blue background
    //scene.setBackgroundBrush(Qt::blue);

    // a gradient background
    //QRadialGradient gradient(0, 0, 10);
    //gradient.setSpread(QGradient::RepeatSpread);
    //scene.setBackgroundBrush(gradient);

    view.show();

*/

    w.show();
    return a.exec();


}
