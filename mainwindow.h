#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPoint move_point; //移动的距离
    bool mouse_press; //鼠标按下
        //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
       //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);
       //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
public slots:
    void next_image_resize(int w, int h);
};

#endif // MAINWINDOW_H
