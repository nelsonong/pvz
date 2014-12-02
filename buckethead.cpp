#include "buckethead.h"

Buckethead::Buckethead()
{
}

Buckethead::Buckethead(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    life = 65;
    attack = 1;
    rate = 0.5;
    speed = 0.8;
    slowed = 0;

    this->setPos(startPos);

    bucketheadPixmap = new QPixmap(":/Images/Buckethead.png");
    *bucketheadPixmap = bucketheadPixmap->scaledToHeight(70);

    attackTimer = new QTime;
    attackTimer->start();
}

Buckethead::~Buckethead()
{
    delete bucketheadPixmap;
    delete attackTimer;
}

void Buckethead::move()
{
    // If zombie position is not zero, keep moving.
    if (xPos > 0)
    {
        // If collision with plant, attack plant.
        QList<QGraphicsItem *> list = scene()->collidingItems(this);
        for (int i = 0; i < list.size(); i++)
        {
            Plant *plant = dynamic_cast<Plant *>(list[i]);
            if (plant)
            {
                if (attackTimer->elapsed() >= rate*1000)
                {
                    plant->life -= attack;
                    return;
                }
            }
        }

        xPos -= speed;
        this->setPos(xPos,yPos);
    }
    else
    {
       Zombie::brainsEaten = true;
    }
}

void Buckethead::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *bucketheadPixmap, boundingRect());
}

QRectF Buckethead::boundingRect() const
{
    return QRectF(0,0,60,70);
}

void Buckethead::advance(int phase)
{
    if (!phase) return;

    move(); // Move zombie.

    // When life gets to 10, buckethead becomes regular.
    if (life <= 10)
    {
        delete bucketheadPixmap;
        bucketheadPixmap = new QPixmap(":/Images/Regular.png");
    }

    // When life goes to 0, zombie dies.
    if (life <= 0)
    {
        Zombie::zombiesKilled++;
        delete this;
    }
}
