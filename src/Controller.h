#pragma once
#include <QObject>
#include <QPainter>
#include <QString>
#include <vector>
#include <optional>
#include "structures/LinkedList.h"
#include "structures/Queue.h"
#include "structures/Stack.h"
#include "structures/BST.h"

struct DemoState
{
    QString algName;
    std::vector<int> listData;
    int currentStep = 0;
};

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(QObject *parent = nullptr);
    void selectAlgorithm(const QString &name);
    void startDemo();
    void stepForward();
    void stepBackward();
    void reset();
    void render(QPainter *p, const QSize &sz);
    bool saveState(const QString &filename);
    bool loadState(const QString &filename);
    void setSpeed(int ms);
    void setAutoPlay(bool);

private:
    void pushState();
    std::vector<DemoState> history;
    int historyIndex = -1;
    DemoState current;
    LinkedList list;
    Queue queue;
    Stack stack;
    BST bst;
    int speedMs = 500;
    bool autoPlay = false;
};