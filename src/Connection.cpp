#include "Connection.h"

Connection::Connection(const QString &n, std::shared_ptr<Shape> a, std::shared_ptr<Shape> b) : Shape(n), m_a(a), m_b(b) {}

void Connection::draw(QPainter *p) const
{
    p->setPen(Qt::DashLine);
    p->drawLine(m_a->center(), m_b->center());
}

QPointF Connection::center() const
{
    QPointF ca = m_a->center(), cb = m_b->center();
    return {(ca.x()+cb.x())/2.0, (ca.y()+cb.y())/2.0};
}
