#ifndef EDGE_H
#define EDGE_H
#pragma once

#include "vertex.h"

class Edge : public QGraphicsItem
{
public:
    inline static int _mode = 1;
    static const int _Arrow_size = 15;
    Vertex* _source;
    Vertex* _target;
    int _weight;
    int _price;
    int _flow = 0;
    QColor _color = Qt::black;

    Edge* reverse = nullptr;

public:
    Edge();
    Edge(Vertex* source, Vertex* target, QColor color = Qt::black, int weight = 1, int price = 0)
        : _source(source), _target(target), _weight(weight), _price(price), _color(color)
    {
        prepareGeometryChange();
    }

    ~Edge()
    {
        _source = nullptr;
        _target = nullptr;

        if (reverse)
        {
            reverse->reverse = nullptr;
            delete reverse;
            reverse = nullptr;
        }
    }

    int GetWeight()
    {
        return _weight;
    }
    void SetWeight(int weight)
    {
        _weight = weight;
        update();
    }
    int GetPrice()
    {
        return _price;
    }
    void SetPrice(int price)
    {
        _price = price;
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

    QRectF boundingRect() const override
    {
        qreal pen_width = 1;
        return QRectF(_source->pos(), _target->pos()).normalized()
            .adjusted(-pen_width, -pen_width, pen_width, pen_width);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);

        QLineF line(_source->pos(), _target->pos());
        painter->setPen(QPen(_color, 2, Qt::SolidLine, Qt::RoundCap));
        painter->drawLine(line);

        QPointF text_pos = (_target->pos() * 3 + _source->pos()) / 4;
        double angle = std::atan2(line.dy(), line.dx());
        QPointF arrow_p1 = text_pos - QPointF(
                               cos(angle + M_PI / 6) * _Arrow_size,
                               sin(angle + M_PI / 6) * _Arrow_size
                               );
        QPointF arrow_p2 = text_pos - QPointF(
                               cos(angle - M_PI / 6) * _Arrow_size,
                               sin(angle - M_PI / 6) * _Arrow_size
                               );

        painter->drawPolygon(QPolygonF() << text_pos << arrow_p1 << arrow_p2);
        QPointF normal(line.dy() / line.length(), -line.dx() / line.length());
        text_pos += normal * 20;

        painter->setPen(Qt::darkGreen);
        QFont font = painter->font();
        font.setPointSize(10);
        painter->setFont(font);

        if (_mode == 1)
            painter->drawText(text_pos, QString::number(_weight) + "/" + QString::number(_price));
        if (_mode == 2)
            painter->drawText(text_pos, QString::number(_weight) + "/" + QString::number(_price) + "/" + QString::number(_flow));

        // if (_mode == 1)
        //     painter->drawText(text_pos, QString::number(_weight));
        // if (_mode == 2)
        //     painter->drawText(text_pos, QString::number(_weight) + "/" + QString::number(_flow));
        // //+ "/" +
    }

};

#endif // EDGE_H
