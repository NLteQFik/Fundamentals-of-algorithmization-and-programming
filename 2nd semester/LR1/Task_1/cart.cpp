#include "cart.h"

Cart::Cart() : MovRect()
{

}

void Cart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    MovRect::paint(painter, option, widget);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);
    painter->setPen(pen);
    painter->setBrush(Qt::gray);
    painter->drawEllipse(x - 50, y + h - 50, 100, 100);
    painter->drawEllipse(x + w - 50, y + h - 50, 100, 100);

    pen.setColor(Qt::yellow);
    pen.setWidth(3);
    switch (slope / koef) {
        case 1:
            painter->drawLine(x - 35, y + h + 35, x + 35, y + h - 35);
            painter->drawLine(x + w - 35, y + h + 35, x + w + 35, y + h - 35);
            break;
        case 2:
            painter->drawLine(x, y + h - 50, x, y + h + 50);
            painter->drawLine(x + w, y + h - 50, x + w, y + h + 50);
            break;
        case 3:
            painter->drawLine(x - 35, y + h - 35, x + 35, y + h + 35);
            painter->drawLine(x + w - 35, y + h - 35, x + w + 35, y + h + 35);
            break;
        default:
            painter->drawLine(x - 50, y + h, x + 50, y + h);
            painter->drawLine(x + w - 50, y + h, x + w + 50, y + h);
            break;
    }
}
