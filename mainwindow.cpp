#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <math.h>

#define RADIUS 100

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //m_scene = new QGraphicsScene();
    //m_scene = new QGraphicsScene(-50, -50, 100, 100);
    m_scene = new QGraphicsScene(-100, -100, 200, 200);

    m_scene->addEllipse(-100, -100, 200, 200);

    m_steelNum = ui->spinBox->value();

    item[0] = NULL;
    on_spinBox_valueChanged(m_steelNum);

    QGraphicsView *view = new QGraphicsView(m_scene);

    view->show();

    ui->verticalLayout->addWidget(view);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int num)
{
    for(int i=0; i<m_steelNum; i++)
    {
        //init channel state
        if(item[0] == NULL)
            break;
        m_scene->removeItem(item[i]);
        delete item[i];
    }

    m_steelNum = num;

    double angle = 1.0*3.14*2/m_steelNum;
    int radius;

    //set radius value
    if(m_steelNum<7)
        radius = 25;
    else if(m_steelNum<11)
        radius = 15;
    else
        radius = 10;

    if(m_steelNum == 1)
    {
        item[0] = new MyItem(radius, RADIUS);
        item[0]->setPos(0, 0);
        item[0]->setToolTip(QString::number(0));
        m_scene->addItem(item[0]);
        return;
    }

    for(int i=0; i<m_steelNum; i++)
    {
        item[i] = new MyItem(radius, RADIUS);
        item[i]->setPos(50*cos(angle * i), 50*sin(angle * i));
        item[i]->setToolTip(QString::number(i));
        m_scene->addItem(item[i]);
    }

}
