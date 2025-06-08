#ifndef ROMB_H
#define ROMB_H

#include "shape.h"

class Romb : public Shape
{
public:
    Romb(int x, int y, int w, int h);
private:
    int w, h;
};

#endif // ROMB_H
