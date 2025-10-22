#include "Controller.h"
#include "StateManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent)
{
    selectAlgorithm("Linked List - Insert");
}

void Controller::selectAlgorithm(const QString &name)
{
    current = DemoState();
    current.algName = name;
    current.listData = {1, 2, 3};
    list.clear();
    queue.clear();
    stack.clear();
    bst.clear();

    for (int v : current.listData)
    {
        list.push_back(v);
        queue.enqueue(v);
        stack.push(v);
        bst.insert(v);
    }
    history.clear();
    historyIndex = -1;
    pushState();
}

void Controller::startDemo()
{
    if (current.algName.contains("Linked List"))
    {
        stepForward();
    }
}

void Controller::stepForward()
{
    if (current.algName.contains("Linked List - Insert"))
    {
        int val = 10 + current.currentStep;
        list.insert_at(1, val);
        current.listData = list.toVector();
    }
    else if (current.algName.contains("Linked List - Delete"))
    {
        if (!list.empty())
            list.remove_at(0);
        current.listData = list.toVector();
    }
    else if (current.algName.contains("Queue"))
    {
        if (current.currentStep % 2 == 0)
            queue.enqueue(100 + current.currentStep);
        else
            queue.dequeue();
        current.listData = queue.toVector();
    }
    else if (current.algName.contains("Stack"))
    {
        if (current.currentStep % 2 == 0)
            stack.push(200 + current.currentStep);
        else
            stack.pop();
        current.listData = stack.toVector();
    }
    else if (current.algName.contains("Binary Tree"))
    {
        if (current.currentStep % 2 == 0)
            bst.insert(50 + current.currentStep);
        else
            bst.remove(50 + current.currentStep - 2);
        current.listData = bst.inorder();
    }

    current.currentStep++;
    pushState();
}
void Controller::stepBackward()
{
    if (historyIndex > 0)
    {
        historyIndex--;
        current = history[historyIndex];
        list.clear();
        for (int v : current.listData)
            list.push_back(v);
    }
}

void Controller::reset()
{
    if (!history.empty())
    {
        historyIndex = 0;
        current = history[0];
        list.clear();
        for (int v : current.listData)
            list.push_back(v);
    }
}

void Controller::pushState()
{
    if (historyIndex + 1 < (int)history.size())
        history.erase(history.begin() + historyIndex + 1, history.end());
    history.push_back(current);
    historyIndex = history.size() - 1;
}
void Controller::render(QPainter *p, const QSize &sz)
{
    p->setPen(Qt::black);
    p->setFont(QFont("Arial", 10));
    int x = 20, y = sz.height() / 2;
    int step = 80;
    for (size_t i = 0; i < current.listData.size(); ++i)
    {
        QRect r(x + i * step, y - 30, 60, 40);
        p->drawRect(r);
        p->drawText(r, Qt::AlignCenter, QString::number(current.listData[i]));
        if (i + 1 < current.listData.size())
        {
            p->drawLine(r.right(), r.center().y(), r.right() + 20, r.center().y());
            QPoint a(r.right() + 20, r.center().y());
            p->drawLine(a.x() - 6, a.y() - 6, a.x(), a.y());
            p->drawLine(a.x() - 6, a.y() + 6, a.x(), a.y());
        }
    }
    p->drawText(10, 20, QString("Algorithm: %1 | Step: %2").arg(current.algName).arg(current.currentStep));
}
bool Controller::saveState(const QString &filename)
{
    QJsonObject root;
    root["alg"] = current.algName;
    QJsonArray arr;
    for (int v : current.listData)
        arr.append(v);
    root["data"] = arr;
    root["step"] = current.currentStep;
    QJsonDocument doc(root);
    QFile f(filename);
    if (!f.open(QIODevice::WriteOnly))
        return false;
    f.write(doc.toJson());
    f.close();
    return true;
}

bool Controller::loadState(const QString &filename)
{
    QFile f(filename);
    if (!f.open(QIODevice::ReadOnly))
        return false;
    QJsonDocument doc = QJsonDocument::fromJson(f.readAll());
    f.close();
    if (!doc.isObject())
        return false;
    QJsonObject root = doc.object();
    current.algName = root["alg"].toString();
    current.listData.clear();
    QJsonArray arr = root["data"].toArray();
    for (auto v : arr)
        current.listData.push_back(v.toInt());
    current.currentStep = root["step"].toInt();
    list.clear();
    for (int v : current.listData)
        list.push_back(v);
    pushState();
    return true;
}
void Controller::setSpeed(int ms) { speedMs = ms; }
void Controller::setAutoPlay(bool b) { autoPlay = b; }