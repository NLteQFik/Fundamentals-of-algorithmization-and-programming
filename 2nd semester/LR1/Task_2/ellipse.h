#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class Ellipse : public Shape
{
public:
    Ellipse(int x, int y, int r_high, int r_low);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    qreal arShape() override;
    qreal perShape() override;

private:
    int r_high, r_low;
};

#endif // ELLIPSE_H
