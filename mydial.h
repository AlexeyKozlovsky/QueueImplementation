#ifndef MYDIAL_H
#define MYDIAL_H

#include <QDial>

class MyDial : public QDial
{
    Q_OBJECT
public:
    MyDial(QWidget *parent = nullptr);

};

#endif // MYDIAL_H
