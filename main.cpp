#include "widget.h"
#include "mylabel.h"
#include "mydial.h"
#include "mywidget.h"

#include <QApplication>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget widget;

    widget.show();
    return a.exec();
}


