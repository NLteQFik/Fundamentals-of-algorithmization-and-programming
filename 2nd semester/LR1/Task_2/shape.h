#ifndef SHAPE_H
#define SHAPE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QLineF>
#include <QVector>
#include <QDebug>
#include <cmath>
#include "mygraphicsitem.h"

class Shape : public MyGraphicsItem
{
public:
    Shape();
    virtual ~Shape() = default;
    Shape(int x, int y);
    void updateBoundingRect();
    void updateBoundingRect(int x, int y, int w, int h);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual qreal perShape();
    virtual qreal arShape();
    //QPointF setCenter();
protected:
    QVector<QPointF> vertices;
    qreal xl, xr, yl, yr;
    int x, y;
private:
    QPointF center;

// signals:
//     void perSignal(qreal per);
//     void arSignal(qreal ar);
//     void oldCent(QPointF old);
//     void curCent(QPointF cur);
};

#endif // SHAPE_H
