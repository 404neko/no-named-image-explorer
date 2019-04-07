#include "MainWindow.h"




void d(QString msg){
    std::cout<<msg.toStdString()<<std::endl;
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

}

MainWindow::~MainWindow(){

}

void MainWindow::mousePressEvent(QMouseEvent *event){
 if(event->button() == Qt::LeftButton){
      mouse_press = true;
      move_point = event->pos();;
 }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if(mouse_press){
       QPoint move_pos = event->globalPos();
       this->move(move_pos - move_point);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    mouse_press = false;
    event->ignore();
}

void MainWindow::next_image_resize(int w, int h){
        this->resize(w+32, h+32);
        this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
}
