#include "Line.h"

Line::Line(const QString &n, const QPointF &a, const QPointF &b) : Shape(n), m_a(a), m_b(b) {}

void Line::draw(QPainter *p) const
{
    p->setPen(Qt::black);
    p->drawLine(m_a, m_b);

    QPointF c = center();
    p->setPen(Qt::black);
    p->drawText(c, name());
}

QPointF Line::center() const
{
    return {(m_a.x() + m_b.x()) / 2.0, (m_a.y() + m_b.y()) / 2.0};
}
