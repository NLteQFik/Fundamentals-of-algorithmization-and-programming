#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h) : Shape(x, y)
{
    this->w = w;
    this->h = h;
    vertices.push_back(QPointF(x - w, y - h));
    vertices.push_back(QPointF(x - w, y + h));
    vertices.push_back(QPointF(x + w, y + h));
    vertices.push_back(QPointF(x + w, y - h));

    updateBoundingRect();
}

//void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    Shape::paint(painter, option, widget);
//    //painter->drawPolygon(vertices.begin(),vertices.size());
//}
