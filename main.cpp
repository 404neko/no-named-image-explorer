#include "mainwindow.h"

#include "mqlabel.h"
#include "mqwidget.h"

#include <QApplication>
#include <QMovie>
#include <QObject>
#include <QPalette>
#include <QStackedLayout>
#include <QWidget>
#include <QFileDialog>
#include <QDir>
#include <QDirIterator>
#include <QFileInfo>

#include <iostream>
#include <filesystem>

QStringList g_filters = {"png", "gif", "jpg", "jpeg", "webp"};

QStringList list_dir(QString path){
    QDir dir(path);
    dir.setFilter(QDir::Files);
    //dir.setSorting(QDir::Name|QDir::Reversed);
    dir.setSorting(QDir::Name);
    QFileInfoList list = dir.entryInfoList();
    int i = 0;
    QStringList path_list;
    do{
        QFileInfo fileInfo = list.at(i);
        if(
                g_filters.indexOf(fileInfo.suffix())!=-1
                                  ){
            path_list.append(fileInfo.absoluteFilePath());
        }
        i++;
    }
    while(i<list.size());
    return path_list;

}

/*/////////////////////////////////////////////
QStringList list_dir(QString path){
    QStringList string_list;
    QDirIterator dirIterator(path,QDir::Files|QDir::NoSymLinks);
    while (dirIterator.hasNext())
    {

        QString temp_path = dirIterator.next();
        QFileInfo temp_info;
        temp_info.setFile(temp_path);
        if(
                g_filters.indexOf(temp_path.split(".").takeLast())!=-1
                //&&
                //temp_info.isFile()
                ){
            string_list<<temp_path;
            d(temp_path);
        }
    }
    string_list.sort();
    return string_list;
}
*/////////////////////////////////////////////

int main(int argc, char *argv[])
{
    //init && set windows
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground);

    //set main widget
    mQWidget* main_widget = new mQWidget();

    //check file path
    QStringList arguments = QCoreApplication::arguments();
    QString file_path = "";
    if(arguments.count()<2){
        file_path = QFileDialog::getOpenFileName(main_widget, QObject::tr("Open Image"), ".", QObject::tr("Image Files(*.jpg *.png *.gif *.webp *.jpeg)"));
        if(file_path.length() == 0){
            exit(0);
        }
        else{
            ;
        }
    }
    else{
        file_path = arguments[1];
    }

    //set main widget and background color
    QPalette pal(main_widget->palette());
    pal.setColor(QPalette::Background, QColor(117,117,117, 128));
    main_widget->setAutoFillBackground(true);
    main_widget->setPalette(pal);

    //stacked layout
    QStackedLayout *stacked_layout = new QStackedLayout;
    main_widget->setLayout(stacked_layout);

    //init image label
    mQLabel *image_label = new mQLabel();
    //QSize size =
    QObject::connect(image_label, SIGNAL(next_image(int,int)), &w, SLOT(next_image_resize(int, int)));
    //QObject::connect(image_label, SIGNAL(next_image(int,int)), main_widget, SLOT(next_image_resize(int, int)));
    image_label->set_image(file_path);
    stacked_layout->addWidget(image_label);
    w.setCentralWidget(main_widget);
    w.show();
    QString dir_path = QFileInfo(file_path).path();
    //std::cout<<dir_path.toStdString();
    image_label->image_list = list_dir(dir_path);

    //image_label->p_mainwindow = &w;









    return a.exec();
}
