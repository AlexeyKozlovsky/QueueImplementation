#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H

#include <QProgressBar>

class MyProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    MyProgressBar(QWidget *parent = nullptr);
};

#endif // MYPROGRESSBAR_H
