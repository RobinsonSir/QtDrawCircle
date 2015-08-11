#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setAcceptDrops(true);
    m_scene = new QGraphicsScene(0, 0, 100, 100);
    m_scene->setSceneRect(-50,-50,100,100);

    QGraphicsEllipseItem *ellipse = m_scene->addEllipse(-100, -100, 200, 200);

    m_steelNum = ui->spinBox->value();

    item[0] = NULL;
    on_spinBox_valueChanged(m_steelNum);

    QGraphicsView *view = new QGraphicsView(m_scene);
    view->setSceneRect(-50, -50, 100, 100);

    view->resize(100,100);
    view->show();
    //setCentralWidget(view);
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
    //qDebug()<<"angle = "<<angle;
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
        item[0] = new MyItem(radius);
        item[0]->setPos(100, 100);
        item[0]->setToolTip(QString::number(0));
        m_scene->addItem(item[0]);
        return;
    }

    for(int i=0; i<m_steelNum; i++)
    {
        item[i] = new MyItem(radius);
        //item[i]->setPos(100 - 50*cos(angle * (2*i+1)), 100 - 50*sin(angle * (2*i+1)));
        item[i]->setPos(100 - 50*cos(angle * i), 100 - 50*sin(angle * i));
        item[i]->setToolTip(QString::number(i));
        //qDebug()<<"i="<<i<<" angle="<<angle * (2*i+1)<<" x="<<cos(angle * (2*i+1))<<",y="<<sin(angle * (2*i+1));
        m_scene->addItem(item[i]);
    }

}
