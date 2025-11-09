#pragma once
#include "Shape.h"

bool isRectangle(const QVector<QPointF> &pts);

class Rectangle : public Shape
{
public:
    Rectangle(const QString &n, const QPointF &a, const QPointF &b);
    Rectangle(const QString &name, const QPointF &a, const QPointF &b, const QPointF &c, const QPointF &d);
    void draw(QPainter *p) const override;
    QPointF center() const override;

private:
    QPointF m_a, m_b, m_c, m_d;
};
