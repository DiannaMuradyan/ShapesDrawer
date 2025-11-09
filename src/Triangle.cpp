#include "Triangle.h"

Triangle::Triangle(const QString &n, const QPointF &a, const QPointF &b, const QPointF &c) : Shape(n)
{
    m_v = {a, b, c};
}

void Triangle::draw(QPainter *p) const
{
    p->setPen(Qt::black);
    p->setBrush(Qt::darkBlue);
    p->drawPolygon(m_v.data(), 3);

    QPointF c = center();
    p->setPen(Qt::white);
    p->drawText(c, name());
}

QPointF Triangle::center() const
{
    return {(m_v[0].x() + m_v[1].x() + m_v[2].x())/3.0, (m_v[0].y() + m_v[1].y() + m_v[2].y())/3.0};
}
