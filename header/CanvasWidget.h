#pragma once
#include <QWidget>
#include <vector>
#include <memory>

class Shape;

class CanvasWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent = nullptr);
    void addShape(std::shared_ptr<Shape> shape);
    void clear();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<std::shared_ptr<Shape>> m_shapes;
};
