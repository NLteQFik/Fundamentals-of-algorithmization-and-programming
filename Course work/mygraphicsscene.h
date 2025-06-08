#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#pragma once

#include "QGraphicsScene"
#include "QGraphicsSceneMouseEvent"

class MyGraphicsScene : public QGraphicsScene
{
public:
    MyGraphicsScene();
    void SetItemIndex(int index);
    void SetItemMode(int index);
    void setActive(bool v);
    bool isActive();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QPointF getPoint();
    QGraphicsItem* getSelectedItem();


private:
    QPointF point;
    int item_index = 0;
    int item_mode = -1;
    bool active = false;
    QGraphicsItem* sel_item;
};

#endif // MYGRAPHICSSCENE_H
