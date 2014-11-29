#include "sunflower.h"

SunFlower::SunFlower()
{
    plantObject.life = 4;
    plantObject.range = 0;
    plantObject.damage = 0;
    plantObject.rate = 24;
    plantObject.splash = 0;
    plantObject.slow = 0;
    plantObject.bomb = 0;
    plantObject.seeding = 7.5;
    plantObject.sun = 1;
    plantObject.need = 0;

    sunFlowerPixmap = (QPixmap(":/Images/Sunflower.png")).scaledToWidth(50);
}

void SunFlower::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), sunFlowerPixmap, boundingRect());
}

QRectF SunFlower::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void SunFlower::advance(int phase)
{

}
