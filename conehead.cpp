#include "conehead.h"

Conehead::Conehead()
{
}

Conehead::Conehead(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    this->life = 28;
    this->attack = 1;
    this->rate = 0.5;
    this->speed = 5;
    this->slowed = 0;

    this->setPos(startPos);
    coneheadPixmap = new QPixmap(":/Images/Conehead.png");
    *coneheadPixmap = coneheadPixmap->scaledToHeight(50);

    this->zombieAttack = new QTime;
    this->zombieAttack->start();

    collisionRect = new QGraphicsRectItem(this->x(), this->y(), coneheadPixmap->width(), coneheadPixmap->height());
}

Conehead::~Conehead()
{
    delete this->zombieAttack;
    delete collisionRect;
}

void Conehead::move()
{
    if (xPos != 0)
    {
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

void Conehead::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *coneheadPixmap, boundingRect());
}

QRectF Conehead::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Conehead::advance(int phase)
{
    if (!phase) return;
    move();

    if (this->life <= 10)
    {
        delete coneheadPixmap;
        coneheadPixmap = new QPixmap(":/Images/Regular.png");
    }

    if (this->life <= 0)
        delete this;
}
