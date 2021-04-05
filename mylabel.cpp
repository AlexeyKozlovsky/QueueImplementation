#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent){

}

void MyLabel::setText(int value) {
    QString strValue = QString::number(value);
    this->QLabel::setText(strValue);
}
