#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H

#include <QGraphicsItem>

class MyGraphicsItem : public QGraphicsItem
{
public:
    MyGraphicsItem();
    void SetAr(qreal ar);
    void setCurAr(qreal ar);
    void SetPer(qreal per);
    void setCurPer(qreal per);
    void SetOld(QPointF old);
    void SetCur(QPointF cur);
    qreal GetAr();
    qreal getCurAr();
    qreal GetPer();
    qreal getCurPer();
    QPointF GetOld();
    QPointF GetCur();
private:
    qreal area, perimiter;
    qreal cur_ar, cur_per;
    QPointF old_p, cur_p;
};

#endif // MYGRAPHICSITEM_H
