#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <shape.h>
#include <QDebug>

class Rectangle : public Shape
{
public:
    Rectangle(int x, int y, int w, int h);
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
private:
    int w, h;
};

#endif // RECTANGLE_H
