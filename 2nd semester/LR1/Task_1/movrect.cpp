#include "movrect.h"

void MovRect::accelerateLeft()
{
    speed -= acceleration;
    if (speed < -max_accel)
        speed = -max_accel;
}

void MovRect::accelerateRight()
{
    speed += acceleration;
    if (speed > max_accel)
        speed = max_accel;
}

void MovRect::decreaseAccel()
{
    if (speed > 0)
    {
        --speed;
        slope = (slope + 4 * koef - 1) % (4 * koef);
    }
    if (speed < 0)
    {
        ++speed;
        slope = (slope + 1) % (4 * koef);
    }
}

void MovRect::move()
{
    x = x + speed;
    if (x > 1200)
        x = -1000;
    if (x < -1200)
        x = 1000;
    update();
}

MovRect::MovRect()
{
    x = -150;
    y = -70;
    w = -2 * x;
    h = -2 * y;
}

void MovRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);
    painter->setPen(pen);
    painter->setBrush(Qt::red);
    painter->drawRect(x, y, w, h);
    update();
}

QRectF MovRect::boundingRect() const
{
    return QRectF(-800, -450, 1600, 900);
}
