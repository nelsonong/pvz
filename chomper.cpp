#include "chomper.h"

Chomper::Chomper()
{
}

Chomper::Chomper(QPoint chomperPos) : rectangleLength(120)
{
    life = 4;
    range = 1;
    damage = 150;
    rate = 42;
    splash = 0;
    slow = 0;
    bomb = 0;
    seeding = 7.5;
    sun = 0;
    need = 0;

    this->setPos(chomperPos);

    chomperPixmap = new QPixmap(":/Images/Chomper.png");
    *chomperPixmap = chomperPixmap->scaledToWidth(50);
    collisionLine = new QGraphicsLineItem(this->x() + 25, this->y(), this->x() + 25, rectangleLength);

    eatZombie = new QTime;
    eatZombie->start();
}

Chomper::~Chomper()
{
    delete chomperPixmap;
    delete collisionLine;
    delete eatZombie;
}

void Chomper::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *chomperPixmap, boundingRect());
}

QRectF Chomper::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void Chomper::advance(int phase)
{
    if (!phase) return;

    QList<QGraphicsItem *> list = scene()->collidingItems(collisionLine);
    for (int i = 0; i < (int)list.size(); i++)
    {
        Zombie *item = dynamic_cast<Zombie *>(list.at(i));
        if (item)
        {
            if (eatZombie->elapsed() >= rate*1000)
            {
                delete item;
            }
        }
    }

    list = scene()->collidingItems(this);
    for (int i = 0; i < (int)list.size(); i++)
    {
        Zombie *item = dynamic_cast<Zombie *>(list.at(i));
        if (item)
        {
            if (zombieAttack->elapsed() >= item->rate*1000)
            {
                life -= item->attack;
                zombieAttack->restart();
            }
        }
    }

    if (life <= 0)
        delete this;
}
