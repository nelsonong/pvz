#include "zombie.h"

bool Zombie::brainsEaten = false;
int Zombie::zombiesKilled = 0;

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
