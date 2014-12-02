#include "bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(Plant *plant) : xPos(plant->x()), yPos(plant->y()), speed(3), damage(plant->damage), slow(plant->slow)
{
    this->setPos(plant->pos());
    bulletPixmap = new QPixmap(":/Images/Bullet.png");
}

Bullet::~Bullet()
{
    delete bulletPixmap;
}

void Bullet::move()
{
    if (this->x() < 1000)        // Once increment has completely decelerated to 0, stop decelerating.
    {
        xPos += speed;    // Initial increment gets decelerated from original random amount.
        this->setPos(xPos,yPos);
    }
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *bulletPixmap, boundingRect());
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0,0,28,28);   // Set boundingRect() to image size.
}

void Bullet::advance(int phase)
{
    if (!phase) return;
    move();

    QList<QGraphicsItem *> list = scene()->collidingItems(this);
    for (int i = 0; i < list.size(); i++)
    {
        Zombie *zombie = dynamic_cast<Zombie *>(list[i]);
        if (zombie)
        {
            zombie->life -= damage;
            if (slow == 1 && zombie->slowed == 0)
            {
                zombie->speed = zombie->speed/2.0;
                zombie->slowed++;
            }
            delete this;
            return;
        }
    }
}
