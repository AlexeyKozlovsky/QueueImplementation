#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QSlider>

class MySlider : public QSlider
{
    Q_OBJECT
public:
    MySlider(QWidget *parent = nullptr);
    MySlider(Qt::Orientation, QWidget *parent = nullptr);
};

#endif // MYSLIDER_H
