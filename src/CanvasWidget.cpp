#include "CanvasWidget.h"
#include "Shape.h"
#include <QPainter>

CanvasWidget::CanvasWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumHeight(500);
    setAutoFillBackground(true);
}

void CanvasWidget::addShape(std::shared_ptr<Shape> shape)
{
    m_shapes.push_back(shape);
    update();
}

void CanvasWidget::clear()
{
    m_shapes.clear();
    update();
}

void CanvasWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    for (auto &s : m_shapes)
        s->draw(&p);
}
