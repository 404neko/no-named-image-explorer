#include "mainwindow.h"
#include <Windows.h>
#include <Windowsx.h>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

}

MainWindow::~MainWindow()
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
 if(event->button() == Qt::LeftButton)
 {
      mouse_press = true;
      //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
      move_point = event->pos();;
 }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //若鼠标左键被按下
    if(mouse_press)
    {
        //鼠标相对于屏幕的位置
        QPoint move_pos = event->globalPos();

       //移动主窗体位置
       this->move(move_pos - move_point);
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //设置鼠标为未被按下

    mouse_press = false;
}

void MainWindow::next_image_resize(int w, int h){
        this->resize(w+128, h+128);
    }
