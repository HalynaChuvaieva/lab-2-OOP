#pragma once
#include <QWidget>
#include <vector>
#include <utility>

class GraphWidget : public QWidget {
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = nullptr);

    void setGraph(const std::vector<int>& vertices, const std::vector<std::pair<int,int>>& edges);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<int> vertices_;
    std::vector<std::pair<int,int>> edges_;
};
