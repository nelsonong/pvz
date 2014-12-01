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
    if (xPos != 0)
    {
        QList<QGraphicsItem *> list = scene()->collidingItems(this);
        for (int i = 0; i < list.size(); i++)
        {
            Plant *item = dynamic_cast<Plant *>(list[i]);
            if (item)
            {
               item->life -= this->attack;
               return;
            }

            LawnMower *item2 = dynamic_cast<LawnMower *>(list[i]);
            if (item2)
            {
                item2->move++;
                delete this;
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
    move();

    if (this->life <= 0)
        delete this;
}
