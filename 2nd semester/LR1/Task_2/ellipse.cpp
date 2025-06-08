#include "ellipse.h"

Ellipse::Ellipse(int x, int y, int r_high, int r_low) : Shape(x, y)
{
    this->r_high = r_high;
    this->r_low = r_low;

    updateBoundingRect(x, y, r_high, r_low);
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(QPointF(x, y), r_high, r_low);
}

qreal Ellipse::arShape()
{
    return M_PI * r_high * r_low;
}

qreal Ellipse::perShape()
{
    return M_PI * (r_high + r_low);
}
