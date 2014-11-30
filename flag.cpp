#include "flag.h"

Flag::Flag()
{
}

Flag::Flag(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    this->life = 10;
    this->attack = 1;
    this->rate = 0.5;
    this->speed = 0.8;
    this->slowed = 0;

    this->setPos(startPos);
    flagPixmap = new QPixmap(":/Images/Flag.png");
    *flagPixmap = flagPixmap->scaledToHeight(50);

    this->zombieAttack = new QTime;
    this->zombieAttack->start();

    collisionRect = new QGraphicsRectItem(this->x(), this->y(), flagPixmap->width(), flagPixmap->height());
}

Flag::~Flag()
{
    delete this->zombieAttack;
    delete this->collisionRect;
}

void Flag::move()
{
    if (xPos != 0)
    {
        collisionRect->setRect(this->x(),this->y(),flagPixmap->width(),flagPixmap->height());
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

void Flag::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *flagPixmap, boundingRect());
}

QRectF Flag::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Flag::advance(int phase)
{
    if (!phase) return;
    move();

    if (this->life <= 0)
        delete this;
}
