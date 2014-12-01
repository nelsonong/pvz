#include "flag.h"

Flag::Flag()
{
}

Flag::Flag(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    life = 10;
    attack = 1;
    rate = 0.5;
    speed = 0.3;
    slowed = 0;

    this->setPos(startPos);

    flagPixmap = new QPixmap(":/Images/Flag.png");
    *flagPixmap = flagPixmap->scaledToHeight(70);

    attackTimer = new QTime;
    attackTimer->start();
}

Flag::~Flag()
{
    delete flagPixmap;
    delete attackTimer;
}

void Flag::move()
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

void Flag::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *flagPixmap, boundingRect());
}

QRectF Flag::boundingRect() const
{
    return QRectF(0,0,60,70);
}

void Flag::advance(int phase)
{
    if (!phase) return;

    move(); // Move zombie.

    // If life gets to 0, zombie dies.
    if (life <= 0)
        delete this;
}
