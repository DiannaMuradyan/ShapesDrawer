#include "Square.h"
#include <QRectF>
#include <cmath>
#include <QVector>

bool isSquare(const QPointF &a, const QPointF &b)
{
    return std::abs(a.x() - b.x()) == std::abs(a.y() - b.y());
}

bool isSquare(const QVector<QPointF> &pts)
{
    auto dist2 = [](const QPointF &a, const QPointF &b) {
        double dx = a.x() - b.x();
        double dy = a.y() - b.y();

        return dx * dx + dy * dy;
    };


    QVector<double> d;
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            d.append(dist2(pts[i], pts[j]));

    std::sort(d.begin(), d.end());

    bool sidesEqual = std::abs(d[0] - d[3]) < 1e-3;
    bool diagsEqual = std::abs(d[4] - d[5]) < 1e-3;
    bool ratioOK = std::abs(d[4] - 2 * d[0]) < 1e-3;

    return sidesEqual && diagsEqual && ratioOK;
}


Square::Square(const QString &n, const QPointF &a, const QPointF &b) : Shape(n), m_a(a), m_b(b) {}

Square::Square(const QString &n, const QPointF &a, const QPointF &b, const QPointF &c, const QPointF &d) : Shape(n)
{
    QVector<QPointF> coords = {a, b, c ,d};

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

void Square::draw(QPainter *p) const
{
    p->setPen(Qt::black);
    p->setBrush(Qt::darkBlue);
    p->drawRect(QRectF(m_a, m_b));

    QPointF c = center();
    p->setPen(Qt::white);
    p->drawText(c, name());
}

QPointF Square::center() const
{
    return {(m_a.x() + m_b.x()) / 2.0, (m_a.y() + m_b.y()) / 2.0};
}
