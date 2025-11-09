#include "Rectangle.h"
#include <QRectF>
#include <QSet>
#include <QVector>
#include <QPointF>


static double dist2(const QPointF &a, const QPointF &b)
{
    double dx = a.x() - b.x();
    double dy = a.y() - b.y();

    return dx * dx + dy * dy;
}


bool isRectangle(const QVector<QPointF> &pts)
{
    if (pts.size() != 4) return false;

    QSet<double> xs, ys;

    for (const auto &p : pts) {
        xs.insert(p.x());
        ys.insert(p.y());
    }

    return xs.size() == 2 && ys.size() == 2;
}



Rectangle::Rectangle(const QString &n, const QPointF &a, const QPointF &b) : Shape(n), m_a(a), m_b(b) {}

Rectangle::Rectangle(const QString &n, const QPointF &a, const QPointF &b, const QPointF &c, const QPointF &d): Shape(n)
{
    QVector<QPointF> coords = {a, b, c, d};

    double minX = coords[0].x(), maxX = coords[0].x();
    double minY = coords[0].y(), maxY = coords[0].y();

    for (const auto &p : coords) {
        minX = std::min(minX, p.x());
        maxX = std::max(maxX, p.x());
        minY = std::min(minY, p.y());
        maxY = std::max(maxY, p.y());
    }

    m_a.setX(minX);
    m_a.setY(minY);

    m_b.setX(maxX);
    m_b.setY(maxY);
}

void Rectangle::draw(QPainter *p) const
{
    p->setPen(Qt::black);
    p->setBrush(Qt::darkBlue);
    p->drawRect(QRectF(m_a, m_b));

    QPointF c = center();
    p->setPen(Qt::white);
    p->drawText(c, name());
}

QPointF Rectangle::center() const
{
    return {(m_a.x() + m_b.x()) / 2.0, (m_a.y() + m_b.y()) / 2.0};
}

