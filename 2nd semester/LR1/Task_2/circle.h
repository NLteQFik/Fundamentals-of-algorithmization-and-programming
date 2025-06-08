#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
public:
    Circle(int x, int y, int radius);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    qreal arShape() override;
    qreal perShape() override;

private:
    int radius;
};

#endif // CIRCLE_H
