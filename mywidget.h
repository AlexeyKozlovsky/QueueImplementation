#ifndef MYWIDGET_H
#define MYWIDGET_H

#include "mylistview.h"
#include "mytimer.h"
#include "queue.h"
#include "queueqobject.h"

#include <QList>
#include <QVBoxLayout>
#include <QWidget>



class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

private:
    const static std::map<int, QString> NUMBERS;
    const unsigned short listViewNumbers = 3;       // Number of queues
    std::vector<MyListView*> listViews;     // Pointer to the queues' array
    std::vector<MyTimer*> timers;        // Timers
    std::vector<int> speeds;        // Speeds for timers


    QList<QWidget> *widgets;    // The list of all widgets on the main widget
    void initComponents();  // Initialize all components
    void makeConnections(); // Make all connections
    void initListWidgets();  // Initialize list widgets
    void initTimers();      // Initilize timers

    // Returns the layout with all components from it
    QVBoxLayout* initOneColumn(int i);   // Initialize components from one column

public slots:
    void addToQueue();
    void startSimulation();
    void update();
};

#endif // MYWIDGET_H
