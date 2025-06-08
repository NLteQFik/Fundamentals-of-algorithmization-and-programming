#include "square.h"

Square::Square(int x, int y, int h) : Shape(x, y)
{
    this->h = h;
    vertices.push_back(QPointF(x - h, y - h));
    vertices.push_back(QPointF(x - h, y + h));
    vertices.push_back(QPointF(x + h, y + h));
    vertices.push_back(QPointF(x + h, y - h));

    updateBoundingRect();
}
