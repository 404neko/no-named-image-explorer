#ifndef MQLABEL_H
#define MQLABEL_H


#include <iostream>

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
#include <QGuiApplication>
#include <QScreen>
#include <QObject>
#include <QEvent>
#include <QLabel>
#include <QSize>
#include <QPixmap>

#include "MainWindow.h"


class mQLabel : public QLabel
{
    Q_OBJECT
public:
    mQLabel();
    ~mQLabel();
    bool key_press(int key_code);
    QSize set_image(QString path);
    QString now;
    QStringList image_list;
    double max_scaled;
    MainWindow* p_mainwindow;

protected:
    void keyPressEvent(QKeyEvent *e);
signals:
    void next_image(int w, int h);
};

#endif // MQLABEL_H
