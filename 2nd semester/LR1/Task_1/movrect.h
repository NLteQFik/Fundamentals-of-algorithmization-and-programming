#ifndef MOVRECT_H
#define MOVRECT_H

#include <QGraphicsItem>
#include <QPainter>

class MovRect : public QGraphicsObject
{
    Q_OBJECT
public slots:
    void accelerateLeft();
    void accelerateRight();
    void decreaseAccel();
    void move();

protected:
    int x, y, w, h;
    int speed = 0;
    const int acceleration = 3, max_accel = acceleration * 30;
    int slope = 0, koef = 3;

public:
    MovRect();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // MOVRECT_H
