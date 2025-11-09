#pragma once
#include "Shape.h"

bool isSquare(const QPointF &a, const QPointF &b); //for creating square with two points
bool isSquare(const QVector<QPointF> &pts); //for creating square with 4 points


class Square : public Shape
{
public:
    Square(const QString &name, const QPointF &a, const QPointF &b);
    Square(const QString &n, const QPointF &a, const QPointF &b, const QPointF &c, const QPointF &d);
    void draw(QPainter *p) const override;
    QPointF center() const override;

private:
    QPointF m_a, m_b;
};
