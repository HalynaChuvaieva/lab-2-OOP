#include "VisualizationWidget.h"
#include "Controller.h"
#include <QPainter>
#include <QMouseEvent>

VisualizationWidget::VisualizationWidget(Controller *c, QWidget *parent) : QWidget(parent), controller(c) {}

void VisualizationWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(rect(), Qt::white);
    controller->render(&p, size());
}

void VisualizationWidget::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
}