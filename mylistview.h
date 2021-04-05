#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include "queueqobject.h"

#include <QListView>
#include <QListWidget>

class MyListView : public QListWidget
{
    Q_OBJECT
public:
    MyListView(const QString &name, QWidget *parent = nullptr);

    void enqueue();
    void dequeue();
    void clear();

private:
    unsigned int counter;
    QString name;
    QueueQObject queue;


public slots:
    void enqueueSlot();
    void dequeueSlot();
    void clearSlot();

signals:
    void dequeueSignal();
};

#endif // MYLISTVIEW_H
