#include "hexagon.h"

Hexagon::Hexagon(int x, int y, int radius) : Shape(x, y)
{
    this->radius = radius;
    for (int i = 0; i < 6; i++) {
        vertices.push_back(QPointF(x + radius * sin(M_PI * 2 / 6 * i), y - radius * cos(M_PI * 2 / 6 * i)));
    }

    updateBoundingRect();
}
