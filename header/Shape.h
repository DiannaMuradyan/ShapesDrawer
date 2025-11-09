#pragma once
#include <QString>
#include <QPainter>
#include <QPointF>
#include <QRectF>

class Shape
{
public:
    explicit Shape(const QString &name) : m_name(name) {}
    virtual ~Shape() = default;

    QString name() const { return m_name; }
    virtual void draw(QPainter *p) const = 0;
    virtual QPointF center() const = 0;

protected:
    QString m_name;
};
