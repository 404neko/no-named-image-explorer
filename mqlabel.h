#ifndef MQLABEL_H
#define MQLABEL_H

#include <QObject>
#include <QEvent>
#include <QLabel>
#include <QSize>
#include <QPixmap>

#include "mainwindow.h"

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
    float max_scaled;
    MainWindow* p_mainwindow;

protected:
    void keyPressEvent(QKeyEvent *e);
signals:
    void next_image(int w, int h);
};

#endif // MQLABEL_H
