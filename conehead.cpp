#include "conehead.h"

Conehead::Conehead()
{
}

Conehead::Conehead(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    life = 28;
    attack = 1;
    rate = 0.5;
    speed = 5;
    slowed = 0;

    this->setPos(startPos);
    coneheadPixmap = new QPixmap(":/Images/Conehead.png");
    *coneheadPixmap = coneheadPixmap->scaledToHeight(50);

    attackTimer = new QTime;
    attackTimer->start();
}

Conehead::~Conehead()
{
    delete attackTimer;;
}

void Conehead::move()
{
    if (xPos != 0)
    {
        QList<QGraphicsItem *> list = scene()->collidingItems(this);
        for (int i = 0; i < list.size(); i++)
        {
            Plant *item = dynamic_cast<Plant *>(list[i]);
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

    if (life <= 10)
    {
        delete coneheadPixmap;
        coneheadPixmap = new QPixmap(":/Images/Regular.png");
    }

    if (life <= 0)
        delete this;
}
