#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>
class Queue
{
public:
    Queue();
    ~Queue();

    int getSize();
    void enqueue(T);
    T dequeue();
    T front();
    bool isEmpty();
    void clear();

private:
    struct QueueNode {
        T data;
        QueueNode *nextPtr;
        QueueNode *prevPtr;
    };

    QueueNode *frontPtr;
    QueueNode *backPtr;
    int size;
};

#include "queue.cpp"
#endif // QUEUE_H
