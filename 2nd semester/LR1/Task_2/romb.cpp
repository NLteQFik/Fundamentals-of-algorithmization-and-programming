#include "romb.h"

Romb::Romb(int x, int y, int w, int h) : Shape(x, y)
{
    this->w = w;
    this->h = h;
    vertices.push_back(QPointF(x - w, y));
    vertices.push_back(QPointF(x, y + h));
    vertices.push_back(QPointF(x + w, y));
    vertices.push_back(QPointF(x, y - h));

    updateBoundingRect();
}
