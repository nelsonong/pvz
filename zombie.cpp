#include "zombie.h"

Zombie::Zombie()
{
}

void Zombie::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *)
{

}

QRectF Zombie::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Zombie::advance(int)
{

}
