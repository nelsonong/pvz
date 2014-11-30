#include "bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(Plant *plant) : xPos(plant->x()), yPos(plant->y())
{
    this->plant = plant;
    this->setPos(plant->pos());
    bulletPixmap = QPixmap(":/Images/Bullet.png");
    damage = plant->damage;

    if (plant->slow == 1)
        this->slow = 1;
}

Bullet::~Bullet()
{
    delete collisionRect;
    delete plant;
}

void Bullet::destroyBullet()
{
    delete this;
}

void Bullet::move()
{
    if (this->x() < 1000)        // Once increment has completely decelerated to 0, stop decelerating.
    {
        xPos += increment;    // Initial increment gets decelerated from original random amount.
        this->setPos(xPos,yPos);
    }
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), bulletPixmap, boundingRect());
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0,0,28,28);   // Set boundingRect() to image size.
}

void Bullet::advance(int phase)
{
    if (!phase) return;
    move();

    collisionRect = new QGraphicsRectItem(this->x(), this->y(), bulletPixmap.width(), bulletPixmap.height());
    QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
    for (int i = 0; i < (int)list.size(); i++)
    {
        Zombie *item = dynamic_cast<Zombie *>(list.at(i));
        if (item)
        {
            delete this;
        }
    }
}

void Bullet::mousePressEvent(QGraphicsSceneMouseEvent *)
{

}
