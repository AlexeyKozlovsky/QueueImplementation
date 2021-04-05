#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QObject>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QWidget *parent = nullptr);

signals:
    void clickedSignal();

};

#endif // MYBUTTON_H
