#include <QApplication>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BST.h"
#include "Graph.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <vector>

// Функція для створення вікна для конкретної структури даних
QWidget* createDataStructureWindow(const QString& title, const std::vector<int>& data) {
    QWidget* window = new QWidget;
    window->setWindowTitle(title);
    window->resize(300, 200);

    QVBoxLayout* layout = new QVBoxLayout(window);

    QLabel* label = new QLabel("Data:");
    layout->addWidget(label);

    // Відображаємо елементи структури
    QString text;
    for (int v : data) {
        text += QString::number(v) + " ";
    }
    QLabel* dataLabel = new QLabel(text);
    layout->addWidget(dataLabel);

    window->setLayout(layout);
    return window;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Дані для структур
    std::vector<int> listData = {1, 2, 3};
    std::vector<int> stackData = {10, 20, 30};
    std::vector<int> queueData = {100, 200, 300};
    std::vector<int> bstData = {5, 3, 7, 2, 4, 6, 8};
    std::vector<int> graphData = {1, 2, 3, 4, 5}; 

    // Створюємо вікна для кожної структури
    QWidget* listWindow = createDataStructureWindow("Linked List", listData);
    QWidget* stackWindow = createDataStructureWindow("Stack", stackData);
    QWidget* queueWindow = createDataStructureWindow("Queue", queueData);
    QWidget* bstWindow = createDataStructureWindow("Binary Search Tree", bstData);
    QWidget* graphWindow = createDataStructureWindow("Graph", graphData);

    // Розташування вікон на екрані
    listWindow->move(100, 100);
    stackWindow->move(450, 100);
    queueWindow->move(800, 100);
    bstWindow->move(100, 350);
    graphWindow->move(450, 350);

    // Показуємо всі вікна
    listWindow->show();
    stackWindow->show();
    queueWindow->show();
    bstWindow->show();
    graphWindow->show();

    return app.exec();
}
