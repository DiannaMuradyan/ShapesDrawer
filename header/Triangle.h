#pragma once
#include "Shape.h"
#include <array>

class Triangle : public Shape
{
public:
    Triangle(const QString &name, const QPointF &a, const QPointF &b, const QPointF &c);
    void draw(QPainter *p) const override;
    QPointF center() const override;

private:
    std::array<QPointF,3> m_v;
};
