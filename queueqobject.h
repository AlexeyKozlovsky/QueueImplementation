#ifndef QUEUEQOBJECT_H
#define QUEUEQOBJECT_H

#include "queue.h"

#include <QObject>

class QueueQObject : public QObject, public Queue<QString>
{
    Q_OBJECT
public:
    QueueQObject();

private:
    unsigned int counter;

signals:
    void enqueueSignal();   // Signal, emited while adding elements to the queue
    void dequeueSignal();   // Signal, emited while removing elements from the queue
    void clearSignal();     // Signal, emited while clearing the queue
};

#endif // QUEUEQOBJECT_H
