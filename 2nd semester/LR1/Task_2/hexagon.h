#ifndef HEXAGON_H
#define HEXAGON_H

#include "shape.h"

class Hexagon : public Shape
{
public:
    Hexagon(int x, int y, int radius);

private:
    int radius;
};

#endif // HEXAGON_H
