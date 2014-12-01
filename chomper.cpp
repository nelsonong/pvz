#include "chomper.h"

Chomper::Chomper()
{
}

Chomper::Chomper(QPoint pos) : rectangleLength(120)
{
    cost = 150;
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

    this->setPos(pos);

    chomperPixmap = new QPixmap(":/Images/Chomper.png");
    *chomperPixmap = chomperPixmap->scaledToWidth(50);

    collisionLine = new QGraphicsLineItem(this->x() + 25, this->y(), rectangleLength, this->y() + 25);

    eatTimer = new QTime;
    eatTimer->start();
}

Chomper::~Chomper()
{
    delete chomperPixmap;
    delete collisionLine;
    delete eatTimer;
}

void Chomper::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *chomperPixmap, boundingRect());
}

QRectF Chomper::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set bounding rect to image size.
}

void Chomper::advance(int phase)
{
    if (!phase) return;

    // If a zombie is found, delete that zombie.
    QList<QGraphicsItem *> list = scene()->collidingItems(collisionLine);
    for (int i = 0; i < list.size(); i++)
    {
        Zombie *plant = dynamic_cast<Zombie *>(list[i]);
        if (plant)
        {
            if (eatTimer->elapsed() >= rate*1000)
            {
                plant->life -= damage;
                return;
            }
        }
    }

    // If life goes under zero, plant is dead.
    if (life <= 0)
        delete this;
}
