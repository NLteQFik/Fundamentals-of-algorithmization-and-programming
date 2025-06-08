#ifndef STAR_H
#define STAR_H

#include "shape.h"

class Star : public Shape
{
public:
    Star(int x, int y, int n, int r_high, int r_low);
private:
    int n, r_high, r_low;
};

#endif // STAR_H
