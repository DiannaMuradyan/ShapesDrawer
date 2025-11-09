#include "ShapeFactory.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"

std::shared_ptr<Shape> ShapeFactory::createShape(
    const QString &type, const QString &name, const QVector<QPointF> &coords)
{
    if (type == "line" && coords.size() == 2)
        return std::make_shared<Line>(name, coords[0], coords[1]);

    if (type == "triangle" && coords.size() == 3)
        return std::make_shared<Triangle>(name, coords[0], coords[1], coords[2]);

    if (type == "rectangle" && coords.size() == 2)
        return std::make_shared<Rectangle>(name, coords[0], coords[1]);

    if (type == "rectangle" && coords.size() == 4 && isRectangle(coords))
        return std::make_shared<Rectangle>(name, coords[0], coords[1], coords[2], coords[3]);

    if (type == "square" && coords.size() == 2 && isSquare(coords[0], coords[1]))
        return std::make_shared<Square>(name, coords[0], coords[1]);

    if (type == "square" && coords.size() == 4 && isSquare(coords))
        return std::make_shared<Square>(name, coords[0], coords[1], coords[2], coords[3]);

    return nullptr;
}
