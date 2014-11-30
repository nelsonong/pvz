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

    zombieAttack = new QTime;
    zombieAttack->start();

    collisionRect = new QGraphicsRectItem(this->x(), this->y(), bucketheadPixmap->width(), bucketheadPixmap->height());
}

Buckethead::~Buckethead()
{
    delete this->zombieAttack;
    delete this->collisionRect;
}

void Buckethead::move()
{
    if (xPos != 0)
    {
        collisionRect->setRect(this->x(),this->y(),bucketheadPixmap->width(),bucketheadPixmap->height());
        QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
        for (int i = 0; i < list.size(); i++)
        {
            Plant *item = dynamic_cast<Plant *>(list.at(i));
            if (item)
            {
                item->life -= this->attack;
                return;
            }
        }

        xPos -= this->speed;
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

    if (this->life <= 10)
    {
        delete bucketheadPixmap;
        bucketheadPixmap = new QPixmap(":/Images/Regular.png");
    }

    if (this->life <= 0)
        delete this;
}
