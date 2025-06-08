#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape
{
public:
    Square(int x, int y, int h);

private:
    int h;
};

#endif // SQUARE_H
