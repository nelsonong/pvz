#include "peashooter.h"

PeaShooter::PeaShooter()
{
    plantObject.life = 4;
    plantObject.range = 9999;
    plantObject.damage = 1;
    plantObject.rate = 1.5;
    plantObject.splash = 0;
    plantObject.slow = 0;
    plantObject.bomb = 0;
    plantObject.seeding = 7.5;
    plantObject.sun = 0;
    plantObject.need = 0;

    peaShooterPixmap = (QPixmap(":/Images/Peashooter.png")).scaledToWidth(50);
}

void PeaShooter::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), peaShooterPixmap, boundingRect());
}

QRectF PeaShooter::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void PeaShooter::advance(int phase)
{

}
