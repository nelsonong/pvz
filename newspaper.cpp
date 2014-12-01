#include "newspaper.h"

Newspaper::Newspaper()
{
}

Newspaper::Newspaper(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    this->life = 16;
    this->attack = 1;
    this->rate = 0.5;
    this->speed = 0.3;
    this->slowed = 0;

    this->setPos(startPos);

    newspaperPixmap = new QPixmap(":/Images/Newspaper.png");
    *newspaperPixmap = newspaperPixmap->scaledToHeight(70);

    this->attackTimer = new QTime;
    this->attackTimer->start();
}

Newspaper::~Newspaper()
{
    delete newspaperPixmap;
    delete attackTimer;
}

void Newspaper::move()
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

void Newspaper::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *newspaperPixmap, boundingRect());
}

QRectF Newspaper::boundingRect() const
{
    return QRectF(0,0,60,70);
}

void Newspaper::advance(int phase)
{
    if (!phase) return;

    move(); // Move zombie.

    // When life gets to 8, newspaper becomes regular and speed doubles.
    if (life <= 8)
    {
        delete newspaperPixmap;
        newspaperPixmap = new QPixmap(":/Images/Regular.png");
        this->speed *= 2;
    }

    // When life gets to 0, zombie dies.
    if (life <= 0)
        delete this;
}
