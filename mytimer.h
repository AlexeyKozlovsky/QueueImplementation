#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>
#include <QObject>

class MyTimer : public QTimer
{
    Q_OBJECT
public:
    MyTimer(QObject *parent = nullptr);
    ~MyTimer();

private:
    const unsigned int MAXINTERVAL = 5000;

public slots:
    void changeInterval(int);
    void stopSlot();
};

#endif // MYTIMER_H
