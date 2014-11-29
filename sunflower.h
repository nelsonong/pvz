#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include "plant.h"

#include <QPixmap>

class SunFlower : public Plant
{
public:
    SunFlower();
    Plant plantObject;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
    QPixmap sunFlowerPixmap;
};

#endif // SUNFLOWER_H
