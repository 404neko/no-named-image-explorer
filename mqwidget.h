#ifndef MQWIDGET_H
#define MQWIDGET_H

#include <QWidget>
#include <QKeyEvent>

class mQWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mQWidget(QWidget *parent = nullptr);
    ~mQWidget();
};

#endif // MQWIDGET_H
