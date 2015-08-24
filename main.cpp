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

    w.show();
    return a.exec();
}
