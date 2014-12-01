#include "flag.h"

Flag::Flag()
{
}

Flag::Flag(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    life = 10;
    attack = 1;
    rate = 0.5;
    speed = 0.8;
    slowed = 0;

    this->setPos(startPos);
    flagPixmap = new QPixmap(":/Images/Flag.png");
    *flagPixmap = flagPixmap->scaledToHeight(50);

    attackTimer = new QTime;
    attackTimer->start();
}

Flag::~Flag()
{
    delete attackTimer;
}

void Flag::move()
{
    if (xPos != 0)
    {
        QList<QGraphicsItem *> list = scene()->collidingItems(this);
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
