#include "mywidget.h"
#include "mydial.h"
#include "mylabel.h"
#include "mylistview.h"
#include "myprogressbar.h"
#include "myslider.h"
#include "mybutton.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QChar>
#include <QTimer>

#include <iostream>

const std::map<int, QString> MyWidget::NUMBERS = {{0, "A"}, {1, "B"}, {2, "C"}};

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    this->widgets = new QList<QWidget>;
    this->initTimers();
    this->initComponents();
    this->initListWidgets();

}

void MyWidget::initComponents() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QGridLayout *grid = new QGridLayout(this);
    for (int i = 0; i < this->listViewNumbers; i++)
        grid->addLayout(initOneColumn(i), 0, i);

    QLabel *mainLabel = new QLabel;
    QFont *font = new QFont;
    font->setBold(true);
    font->setPointSize(18);

    mainLabel->setText("Queue Simulator");
    mainLabel->setFont(*font);
    mainLabel->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(mainLabel);
    mainLayout->addLayout(grid);

    QPushButton *mainButton = new QPushButton;
    mainButton->setText("Start simulation");

    QObject::connect(mainButton, SIGNAL(clicked()),
                     this, SLOT(startSimulation()));

    QPushButton *stopSimulationButton = new QPushButton;
    stopSimulationButton->setText("Stop simulation");

    for (uint i = 0; i < this->timers.size(); i++) {
        QObject::connect(stopSimulationButton, SIGNAL(clicked()),
                         this->timers[i], SLOT(stopSlot()));
    }

    mainLayout->addWidget(mainButton);
    mainLayout->addWidget(stopSimulationButton);

    this->setLayout(mainLayout);
}

void MyWidget::initListWidgets() {

}

void MyWidget::initTimers() {
    for (int i = 0; i < this->listViewNumbers; i++){
        MyTimer *timer = new MyTimer(this);
        this->timers.push_back(timer);
    }
}

void MyWidget::makeConnections() {

}

QVBoxLayout* MyWidget::initOneColumn(int i) {
    QVBoxLayout *result = new QVBoxLayout(this);

    MyListView *list = new MyListView(MyWidget::NUMBERS.at(i), this);
    this->listViews.push_back(list);

    MyProgressBar *progressBar = new MyProgressBar(this);
    MySlider *slider = new MySlider(Qt::Horizontal, this);
    MyButton *button = new MyButton(this);
    button->setText("Add to queue " + MyWidget::NUMBERS.at(i));

    QObject::connect(button, SIGNAL(clicked()),
                     this, SLOT(addToQueue()));

    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     this->timers[i], SLOT(changeInterval(int)));

    QObject::connect(this->timers[i], &QTimer::timeout,
                     list, &MyListView::dequeueSlot);

    QObject::connect(this->timers[i], SIGNAL(timeout()),
                     this, SLOT(update()));

//    QObject::connect(list, SIGNAL(dequeueSignal()),
//                     this->timers[i], SLOT(stopSlot()));


    result->addWidget(list);
    result->addWidget(progressBar);
    result->addWidget(slider);

//    QGridLayout *grid = new QGridLayout(this);
//    for (int i = 0; i < 2; i++) {
//        MyDial *dial = new MyDial(this);
//        MyLabel *label = new MyLabel(this);

//        label->QLabel::setText("0");
//        label->setAlignment(Qt::AlignCenter);

//        connect(dial, SIGNAL(valueChanged(int)),
//                label, SLOT(setText(int)));

//        grid->addWidget(dial, 0, i);
//        grid->addWidget(label, 1, i);
//    }

//    result->addLayout(grid);
    result->addWidget(button);

    return result;
}

void MyWidget::addToQueue() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());


    this->listViews[(int)button->text().back().toLatin1() - (int)'A']->enqueue();
    std::cout << "OKEY" << std::endl;
}

void MyWidget::startSimulation() {
    for (uint i = 0; i < this->timers.size(); i++)
        this->timers[i]->start();

    qDebug() << "Simulation started";
}

void MyWidget::update() {
    qDebug() << "timer!";
}

