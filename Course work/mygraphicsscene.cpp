#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene()
{

}

void MyGraphicsScene::SetItemIndex(int index)
{
    this->item_index = index;
}

void MyGraphicsScene::SetItemMode(int index)
{
    this->item_mode = index;
}

void MyGraphicsScene::setActive(bool v)
{
    this->active = v;
}

bool MyGraphicsScene::isActive()
{
    return active;
}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (item_mode == 4)
    {
        event->ignore();
        return;
    }

    point = event->scenePos();
    QGraphicsItem* new_item = itemAt(point, QTransform());

    if (sel_item != new_item)
    {
        sel_item = new_item;
        active = true;
    }
    if (item_mode > 0)
    {
        active = true;
        return;
    }
    QGraphicsScene::mousePressEvent(event);
}

QPointF MyGraphicsScene::getPoint()
{
    return point;
}

QGraphicsItem* MyGraphicsScene::getSelectedItem()
{
    return sel_item;
}














