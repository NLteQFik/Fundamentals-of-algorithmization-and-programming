#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape
{
public:
    Triangle(int x, int y, int radius);

private:
    int radius;
};

#endif // TRIANGLE_H
