#include "mygraphicsitem.h"

MyGraphicsItem::MyGraphicsItem() {}

void MyGraphicsItem::SetAr(qreal ar)
{
    area = ar;
    cur_ar = ar;
}

void MyGraphicsItem::setCurAr(qreal ar)
{
    cur_ar = ar;
}

void MyGraphicsItem::SetPer(qreal per)
{
    perimiter = per;
    cur_per = per;
}

void MyGraphicsItem::setCurPer(qreal per)
{
    cur_per = per;
}

void MyGraphicsItem::SetOld(QPointF old)
{
    old_p = old;
}

void MyGraphicsItem::SetCur(QPointF cur)
{
    cur_p = cur;
}

qreal MyGraphicsItem::GetAr()
{
    return area;
}

qreal MyGraphicsItem::getCurAr()
{
    return cur_ar;
}

qreal MyGraphicsItem::GetPer()
{
    return perimiter;
}

qreal MyGraphicsItem::getCurPer()
{
    return cur_per;
}

QPointF MyGraphicsItem::GetOld()
{
    return old_p;
}

QPointF MyGraphicsItem::GetCur()
{
    return cur_p;
}
