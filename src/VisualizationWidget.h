#pragma once
#include <QWidget>
#include <memory>
class Controller;

class VisualizationWidget : public QWidget
{
    Q_OBJECT
public:
    VisualizationWidget(Controller *c, QWidget *parent = nullptr);
    QSize minimumSizeHint() const override { return QSize(400, 300); }

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;

private:
    Controller *controller;
};