#pragma once
#include <QMainWindow>
#include <memory>

class VisualizationWidget;
class Controller;
class QListWidget;
class QPushButton;
class QTableWidget;
class QTreeWidget;
class QStackedWidget;
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
private slots:
    void onAlgorithmSelected();
    void onStartDemo();
    void onStepForward();
    void onStepBackward();
    void onSaveState();
    void onLoadState();
    void onOpenAbout();
    void onReset();
    void onSpeedChanged(int);
    void onToggleAutoPlay(bool);

private:
    void createUI();
    VisualizationWidget *viz;
    Controller *controller;

    QListWidget *algList;
    QPushButton *btnStart;
    QPushButton *btnForward;
    QPushButton *btnBack;
    QPushButton *btnSave;
    QPushButton *btnLoad;
    QPushButton *btnReset;
    QTableWidget *infoTable;
    QTreeWidget *structureTree;
    QStackedWidget *stacked;
    QLineEdit *stateName;
};
