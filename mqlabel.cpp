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

#include <iostream>

using namespace std;

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

    QSize size;

    if(animated){
        QMovie *movie = new QMovie(file_path);
        QImage *image = new QImage(file_path);
        size = image->size();
        this->setMovie(movie);
        this->setAlignment(Qt::AlignCenter);
        movie->start();
    }
    else{
        QImage image(file_path);
        size = image.size();
        float scaled_width = size.width()/screen_width;
        float scaled_height = size.height()/screen_height;
        if(scaled_height>1.0||scaled_width>1.0){
            this->max_scaled = std::max(scaled_height, scaled_width) + 1;
        }
        QPixmap pixmap = QPixmap::fromImage(image).scaled(size.width()/max_scaled, size.height()/max_scaled, Qt::KeepAspectRatio);//.scaled(size.height()/max_scaled, size.width()/max_scaled, Qt::KeepAspectRatio);
        this->setPixmap(pixmap);
        this->setAlignment(Qt::AlignCenter);
        //this->next_image(30, 30);
    }
    return size;
}

mQLabel::~mQLabel(){
    ;
}
/*
void mQLabel::next_image(int w, int h){
    ;
}*/
