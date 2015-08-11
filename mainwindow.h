#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myitem.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void on_spinBox_valueChanged(int num);

private:
    Ui::MainWindow *ui;
    MyItem *item[50];
    int m_steelNum;
    QGraphicsScene *m_scene;

};

#endif // MAINWINDOW_H
