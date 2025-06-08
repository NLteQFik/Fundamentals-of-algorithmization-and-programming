#ifndef VERTEX_H
#define VERTEX_H
#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QLineF>
#include <cmath>

class Vertex : public QGraphicsItem
{
    friend class Graph;
private:
    static const int _Radius = 15;
    float _x, _y;
    int _index = 0;
    QString _name;
    QColor _color;

public:
    Vertex();
    Vertex(float x, float y, QString name = "", QColor color = Qt::white)
        : _x(x) , _y(y), _name(name), _color(color)
    {
        setPos(x, y);
        setFlag(ItemIsMovable);
        setFlag(ItemSendsGeometryChanges);
        setZValue(2);
    }

    ~Vertex()
    {

    }

    QString GetName()
    {
        return _name;
    }
    void SetName(const QString name)
    {
        _name = name;
        update();
    }

    QColor GetColor()
    {
        return _color;
    }
    void SetColor(const QColor color)
    {
        _color = color;
        update();
    }
    void SetColorByName()
    {
        if (_name[0] == "S")
            _color = Qt::cyan;
        else if (_name[0] == "T")
            _color = Qt::magenta;
        else
            _color = Qt::white;

        update();
    }

    QRectF boundingRect() const override
    {
        return QRectF(-_Radius, -_Radius, 2 * _Radius, 2 * _Radius);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);

        painter->setBrush(_color);
        painter->setPen(Qt::black);
        painter->drawEllipse(-_Radius, -_Radius, 2 * _Radius, 2 * _Radius);

        painter->setPen(Qt::black);
        QFont font = painter->font();
        font.setPointSize(10);
        painter->setFont(font);
        painter->drawText(boundingRect(), Qt::AlignCenter, _name);
    }

    QVariant itemChange(GraphicsItemChange change, const QVariant& value) override
    {
        if (change == ItemPositionChange)
            for (int i = 0; i < 5; i++) i++;
        return QGraphicsItem::itemChange(change, value);
    }


};

#endif // VERTEX_H
