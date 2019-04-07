#include "mQLabel.h"




using namespace std;

mQLabel::mQLabel(){
    this->setFocusPolicy(Qt::StrongFocus);
    this->max_scaled = 1.0;
}

void mQLabel::keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_Right){
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
    if(e->key() == Qt::Key_Left){
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

    if(e->key() == Qt::Key_Escape){
        exit(0);
    }
}

QSize mQLabel::set_image(QString file_path){
    this->max_scaled = 1.0;
    this->now = file_path;
    bool animated = false;
    if(file_path.endsWith("gif")||file_path.endsWith("webp")){
        animated = true;
    }

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen->geometry();
    int screen_width = rect.width();
    int screen_height = rect.height();
    QImage image(file_path);
    QSize size = image.size();
    int set_width = 0;
    int set_height = 0;
    if(size.width()>(screen_width-32)||size.height()>(screen_height-32)){
        this->max_scaled = std::max(
                    (size.width()+0.0)/screen_width,
                    (size.height()+0.0)/screen_height
                    );
        set_width = static_cast<int>(size.width()/this->max_scaled-64);
        set_height = static_cast<int>(size.height()/this->max_scaled-64);
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
    return size;
}

mQLabel::~mQLabel(){
    ;
}

