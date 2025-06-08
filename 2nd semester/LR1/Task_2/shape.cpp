#include "shape.h"

Shape::Shape()
{

}

Shape::Shape(int x, int y)
{
    //setFlag(QGraphicsItem::ItemIsMovable);
    this->x = x;
    this->y = y;
}

void Shape::updateBoundingRect()
{
    xl = 100000; yl = 100000; xr = -100000; yr = -100000;
    for (int i = 0; i < vertices.size(); i++)
    {
        QPointF point = vertices.at(i);
        qreal x = point.x();
        qreal y = point.y();
        xl = xl > x ? x : xl;
        xr = xr < x ? x : xr;
        yl = yl > y ? y : yl;
        yr = yr < y ? y : yr;
    }
}

void Shape::updateBoundingRect(int x, int y, int w, int h)
{
    xl = x - w;
    xr = x + w;
    yl = y - h;
    yr = y + h;
}

QRectF Shape::boundingRect() const
{
    return QRectF(QPointF(xl, yl), QPointF(xr, yr));
}

void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPolygon(vertices.begin(), vertices.size());
}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //this->x = event->pos().x();
    //this->y = event->pos().y();
    //QGraphicsItem::mousePressEvent(event);
    //qDebug() << "loh 1";
    //setPos(mapToScene(event->pos()));
    //setPos(event->scenePos());

    SetAr(arShape());
    SetPer(perShape());
    SetOld(QPointF(x, y));
    SetCur(mapToScene(event->pos().x(), event->pos().y()));
    qDebug() << x << " " << y;

    //setPos(mapToScene(event->pos().x() - x, event->pos().y() - y));
    setPos(event->scenePos().x() - x, event->scenePos().y() - y);
    //emit perSignal(perShape());
    //emit arSignal(arShape());
    //emit oldCent(QPointF(x, y));
    //emit curCent(mapToScene(event->pos().x(), event->pos().y()));
}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SetAr(arShape());
    SetPer(perShape());
    SetOld(QPointF(x, y));
    SetCur(mapToScene(event->pos().x(), event->pos().y()));
    qDebug() << x << " " << y;

    //setPos(mapToScene(event->pos().x() - x, event->pos().y() - y));
    setPos(event->scenePos().x() - x, event->scenePos().y() - y);
    // emit perSignal(perShape());
    // emit arSignal(arShape());
    // emit oldCent(QPointF(x, y));
    // emit curCent(mapToScene(event->pos().x(), event->pos().y()));
    //setPos(event->scenePos());

    //qDebug() << event->pos().x() << " " << event->pos().y();
    //this->x = event->scenePos().x();
    //this->y = event->scenePos().y();
    //qDebug() << x << " " << y;

    //QGraphicsItem::mouseMoveEvent(event);
    //return;
}

qreal Shape::arShape()
{
    qreal ar = 0;
    for (int i = 0; i < vertices.size(); i++) {
        QPointF temp = (i + 1 != vertices.size() ? vertices[i + 1] : vertices[0]);
        ar += temp.x() * vertices[i].y() - temp.y() * vertices[i].x();
    }
    return std::fabs(ar) / 2;
}

qreal Shape::perShape()
{
    qreal per = 0;
    for (int i = 0; i < vertices.size(); i++) {
        QPointF temp = (i + 1 != vertices.size() ? vertices[i + 1] : vertices[0]);
        per += QLineF(temp, vertices[i]).length();
    }
    return per;
}
