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

bool MyGraphicsScene::getActive()
{
    return active;
}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    point = event->scenePos();
    sel_item = static_cast<MyGraphicsItem*>(itemAt(point, QTransform()));
    if (item_mode == 0 || item_mode == 2)
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

MyGraphicsItem* MyGraphicsScene::getSelectedItem()
{
    return sel_item;
}

