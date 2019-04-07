#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
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
#include <QMainWindow>
 
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPoint move_point;
    bool mouse_press;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
public slots:
    void next_image_resize(int w, int h);
};

#endif // MAINWINDOW_H
