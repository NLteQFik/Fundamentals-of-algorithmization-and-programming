#include "circle.h"

Circle::Circle(int x, int y, int r) : Shape(x, y)
{
    this->radius = r;

    updateBoundingRect(x, y, r, r);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(QPointF(x, y), radius, radius);
}

qreal Circle::arShape()
{
    return M_PI * radius * radius;
}

qreal Circle::perShape()
{
    return 2 * M_PI * radius;
}
