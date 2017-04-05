#include "mqlabel.h"

#include <QKeyEvent>
#include <QMovie>
#include <QImage>
#include <QObject>
#include <QMessageBox>
#include <QSize>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QPainter>
#include <QPixmap>

#include <iostream>

using namespace std;

void d(QString msg){
    std::cout<<msg.toStdString()<<std::endl;
}

mQLabel::mQLabel(){
    this->setFocusPolicy(Qt::StrongFocus);
    this->max_scaled = 1.0;
}

void mQLabel::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Right)
    {
        if(this->image_list.isEmpty()){
            ;
        }
        else{
            int index = this->image_list.indexOf(this->now);
            if(index+1<this->image_list.length()&&index!=-1){
                QString next = (this->image_list)[index+1];
                this->now = next;
                this->set_image(next);
                return ;
            }
        }
    }
    if(e->key() == Qt::Key_Left)
    {
        if(this->image_list.isEmpty()){
            ;
        }
        else{
            int index = this->image_list.indexOf(this->now);
            if(index-1>=0&&index!=-1){
                QString next = (this->image_list)[index-1];
                this->now = next;
                this->set_image(next);
                return ;
            }
        }
    }
}

QSize mQLabel::set_image(QString file_path){
    this->max_scaled = 1.0;
    this->now = file_path;
    bool animated = false;
    if(file_path.endsWith("gif")||file_path.endsWith("webp")){
        animated = true;
    }

    QDesktopWidget *desktop = QApplication::desktop();
    QRect screen = desktop->screenGeometry();
    int screen_width = screen.width();
    int screen_height = screen.height();
    QImage image(file_path);
    QSize size = image.size();
    int set_width = 0;
    int set_height = 0;
    if(size.width()>(screen_width-32)||size.height()>(screen_height-32)){
        this->max_scaled = std::max(
                    (size.width()+0.0)/screen_width,
                    (size.height()+0.0)/screen_height
                    );
        set_width = size.width()/this->max_scaled-64;
        set_height = size.height()/this->max_scaled-64;
    }
    else{
        set_width = size.width();
        set_height = size.height();
    }

    if(animated){
        QMovie *movie = new QMovie(file_path);
        this->setMovie(movie);
        this->setAlignment(Qt::AlignCenter);
        movie->start();

    }
    else{
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(set_width, set_height, Qt::KeepAspectRatio);
        this->setPixmap(pixmap);
        this->setAlignment(Qt::AlignCenter);
    }
    this->next_image(set_width, set_height);
    d(QString::number(this->max_scaled));
    d(QString::number(set_height));

    return size;
}

mQLabel::~mQLabel(){
    ;
}

