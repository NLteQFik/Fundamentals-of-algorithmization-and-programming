#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include "mygraphicsitem.h"
#include "QGraphicsScene"
#include "QGraphicsSceneMouseEvent"

class MyGraphicsScene : public QGraphicsScene
{
public:
    MyGraphicsScene();
    void SetItemIndex(int index);
    void SetItemMode(int index);
    void setActive(bool v);
    bool getActive();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QPointF getPoint();
    MyGraphicsItem* getSelectedItem();


private:
    QPointF point;
    int item_index = 0;
    int item_mode = -1;
    bool active = false;
    MyGraphicsItem* sel_item;
};

#endif // MYGRAPHICSSCENE_H
