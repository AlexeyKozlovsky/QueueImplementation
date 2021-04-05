#include "mylistview.h"

MyListView::MyListView(const QString &name, QWidget *parent) : QListWidget(parent)
{
    this->counter = 1;
    this->name = name;
}

void MyListView::enqueue() {
    QString label = name + QString::number(this->counter);
    this->queue.enqueue(label);
    this->addItem(label);

    this->counter++;
}

void MyListView::dequeue() {
    if (this->queue.isEmpty()) {
        emit dequeueSignal();
        return;
    }

    QListWidgetItem *item = this->item(0);
    delete item;
    this->queue.dequeue();


    qDebug() << "Dequeued";
}

void MyListView::clear() {
    this->QListWidget::clear();
    this->queue.clear();
}

void MyListView::enqueueSlot() {
    this->enqueue();
}

void MyListView::dequeueSlot() {
    this->dequeue();
}

void MyListView::clearSlot() {
    this->clear();
}
