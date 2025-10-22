#include "MainWindow.h"
#include "VisualizationWidget.h"
#include "Controller.h"
#include "StateManager.h"
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QCheckBox>
#include <QTableWidget>
#include <QTreeWidget>
#include <QStackedWidget>
#include <QLineEdit>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    controller = new Controller(this);
    createUI();
}

void MainWindow::createUI()
{
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    algList = new QListWidget;
    algList->addItems({"Linked List - Insert",
                       "Linked List - Delete",
                       "Queue - Enqueue/Dequeue",
                       "Stack - Push/Pop",
                       "Binary Tree - Insert/Delete",
                       "Array - Insertion Sort"});

    btnStart = new QPushButton("Start Demo");
    btnForward = new QPushButton("Step >>");
    btnBack = new QPushButton("<< Step");
    btnSave = new QPushButton("Save State");
    btnLoad = new QPushButton("Load State");
    btnReset = new QPushButton("Reset");

    stateName = new QLineEdit;
    stateName->setPlaceholderText("state_name.json");

    QSlider *speed = new QSlider(Qt::Horizontal);
    speed->setRange(100, 2000);
    QLabel *speedLabel = new QLabel("Speed ms:");
    QCheckBox *autoPlay = new QCheckBox("Auto-play");

    infoTable = new QTableWidget(4, 2);
    infoTable->setHorizontalHeaderLabels({"Var", "Value"});
    infoTable->setItem(0, 0, new QTableWidgetItem("i"));

    structureTree = new QTreeWidget;
    structureTree->setHeaderLabel("Structure View");
    structureTree->addTopLevelItem(new QTreeWidgetItem({"Root"}));

    viz = new VisualizationWidget(controller, this);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(new QLabel("Algorithms"));
    leftLayout->addWidget(algList);
}