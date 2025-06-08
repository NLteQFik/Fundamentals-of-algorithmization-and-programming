#ifndef CART_H
#define CART_H

#include "movrect.h"

class Cart : public MovRect
{
public:
    Cart();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // CART_H
