#pragma once
#include "Shape.h"

class Line : public Shape
{
public:
    Line(const QString &name, const QPointF &a, const QPointF &b);
    void draw(QPainter *p) const override;
    QPointF center() const override;

private:
    QPointF m_a, m_b;
};
