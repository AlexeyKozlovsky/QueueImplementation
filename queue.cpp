#include "queue.h"
#include <iostream>


template <typename T>
Queue<T>::Queue() {
    this->frontPtr = nullptr;
    this->backPtr = nullptr;
    this->size = 0;
}

template <typename T>
Queue<T>::~Queue() {
    //this->clear();
}

template <typename T>
void Queue<T>::enqueue(T data) {
    // Creating a new node
    QueueNode *node = new QueueNode;
    node->data = data;
    node->prevPtr = this->backPtr;
    node->nextPtr = nullptr;

    QueueNode *oldBackNode = this->backPtr;
    if (!oldBackNode) this->frontPtr = node;
    else oldBackNode->nextPtr = node;

    this->backPtr = node;

    this->size++;
}

template <typename T>
T Queue<T>::dequeue() {
    if (this->isEmpty()) std::out_of_range("Queue is already empty");

    QueueNode *currentNode = this->frontPtr;
    if (this->size > 1) this->frontPtr = currentNode->nextPtr;
    else {
        this->frontPtr = nullptr;
        this->backPtr = nullptr;
    }

    T result = currentNode->data;
    delete currentNode;
    this->size--;

    return result;
}


template <typename T>
T Queue<T>::front() {
    return this->frontPtr->data;
}

template <typename T>
void Queue<T>::clear() {
    while (!this->isEmpty()) this->dequeue();
}

template <typename T>
bool Queue<T>::isEmpty() {
    return this->size == 0;
}

template <typename T>
int Queue<T>::getSize() {
    return this->size;
}




