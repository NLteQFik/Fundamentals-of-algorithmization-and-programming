#include "triangle.h"

Triangle::Triangle(int x, int y, int radius) : Shape(x, y)
{
    this->radius = radius;
    for (int i = 0; i < 3; i++) {
        vertices.push_back(QPointF(x + radius * sin(M_PI * 2 / 3 * i), y - radius * cos(M_PI * 2 / 3 * i)));
    }

    updateBoundingRect();
}
