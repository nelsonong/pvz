#include "conehead.h"
#include <QColor>

Conehead::Conehead()
{
}

Conehead::Conehead(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    life = 28;
    attack = 1;
    rate = 0.5;
    speed = 0.8;
    slowed = 0;

    this->setPos(startPos);

    coneheadPixmap = new QPixmap(":/Images/Conehead.png");
    *coneheadPixmap = coneheadPixmap->scaledToHeight(50);

    attackTimer = new QTime;
    attackTimer->start();
}

Conehead::~Conehead()
{
    delete coneheadPixmap;
    delete attackTimer;;
}

void Conehead::move()
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
                coneheadPixmap->fill(QColor(255,0,0,200));
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

    move(); // Move zombie.

    // When life gets to 10, conehead becomes regular.
    if (life <= 10)
    {
        delete coneheadPixmap;
        coneheadPixmap = new QPixmap(":/Images/Regular.png");
    }

    // When life gets to 0, zombie dies.
    if (life <= 0)
    {
        Zombie::zombiesKilled++;
        delete this;
    }
}
