#pragma once
#include "Shape.h"
#include <memory>

class Connection : public Shape
{
public:
    Connection(const QString &name, std::shared_ptr<Shape> a, std::shared_ptr<Shape> b);
    void draw(QPainter *p) const override;
    QPointF center() const override;

private:
    std::shared_ptr<Shape> m_a, m_b;
};
