#include "regular.h"

Regular::Regular()
{

}

Regular::Regular(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    life = 10;
    attack = 1;
    rate = 0.5;
    speed = 1.0;

    this->setPos(xPos, yPos);
    regularPixmap = new QPixmap(":/Images/Regular.png");
    *regularPixmap = regularPixmap->scaledToHeight(70);

    attackTimer = new QTime;
    attackTimer->start();
}

Regular::~Regular()
{
    delete attackTimer;
}

void Regular::move()
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

void Regular::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *regularPixmap, boundingRect());
}

QRectF Regular::boundingRect() const
{
    return QRectF(0,0,60,70);
}

void Regular::advance(int phase)
{
    if (!phase) return;

    move(); // Move zombie.

    // When life gets to 0, zombie dies.
    if (life <= 0)
        delete this;
}
