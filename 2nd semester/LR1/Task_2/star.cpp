#include "star.h"

Star::Star(int x, int y, int n, int r_high, int r_low) : Shape(x, y)
{
    this->n = n;
    this->r_high = r_high;
    this->r_low = r_low;
    for (int i = 0; i < 2 * n; i++) {
        if (i % 2)
            vertices.push_back(QPointF(x + r_low * sin(M_PI / n * i), y - r_low * cos(M_PI / n * i)));
        else
            vertices.push_back(QPointF(x + r_high * sin(M_PI / n * i), y - r_high * cos(M_PI / n * i)));
    }

    updateBoundingRect();
}
