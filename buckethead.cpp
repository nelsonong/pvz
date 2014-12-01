#include "buckethead.h"

Buckethead::Buckethead()
{
}

Buckethead::Buckethead(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    life = 65;
    attack = 1;
    rate = 0.5;
    speed = 5;
    slowed = 0;

    this->setPos(startPos);
    bucketheadPixmap = new QPixmap(":/Images/Buckethead.png");
    *bucketheadPixmap = bucketheadPixmap->scaledToHeight(50);

    attackTimer = new QTime;
    attackTimer->start();
}

Buckethead::~Buckethead()
{
    delete attackTimer;
}

void Buckethead::move()
{
    if (xPos != 0)
    {
        QList<QGraphicsItem *> list = scene()->collidingItems(this);
        for (int i = 0; i < list.size(); i++)
        {
            Plant *item = dynamic_cast<Plant *>(list.at(i));
            if (item)
            {
                item->life -= attack;
                return;
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
    return QRectF(0,0,50,50);
}

void Buckethead::advance(int phase)
{
    if (!phase) return;
    move();

    if (life <= 10)
    {
        delete bucketheadPixmap;
        bucketheadPixmap = new QPixmap(":/Images/Regular.png");
    }

    if (life <= 0)
        delete this;
}
