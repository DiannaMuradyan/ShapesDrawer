#pragma once
#include <memory>
#include <QString>
#include <QVector>
#include <QPointF>

class Shape;

class ShapeFactory
{
public:
    static std::shared_ptr<Shape> createShape(const QString &type, const QString &name, const QVector<QPointF> &coords);
};
