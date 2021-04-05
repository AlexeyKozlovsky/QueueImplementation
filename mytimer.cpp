#include "mytimer.h"
#include <QDebug>

MyTimer::MyTimer(QObject *parent) : QTimer(parent)
{
    this->setInterval(this->MAXINTERVAL);
}

MyTimer::~MyTimer() {
    this->stop();
}

void MyTimer::changeInterval(int x) {
    this->setInterval(MAXINTERVAL - 50 * x);

    qDebug() << "interval changed " << QString::number(this->interval());
}

void MyTimer::stopSlot() {
    this->stop();
}
