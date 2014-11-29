#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include "plant.h"

#include <QGraphicsItem>
#include <QPainter>

class PeaShooter : public Plant
{
public:
    PeaShooter();
    Plant plantObject;
    QPixmap peaShooterPixmap;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // PEASHOOTER_H
