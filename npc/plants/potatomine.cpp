#include "potatomine.h"

PotatoMine::PotatoMine()
{
}

PotatoMine::PotatoMine(QPoint potatoMinePos) : exploded(0)
{
    cost = 25;
    life = 4;
    range = 1;
    damage = 90;
    rate = 15;
    splash = 0;
    slow = 0;
    bomb = 1;
    seeding = 30;
    sun = 0;
    need = 0;

    this->setPos(potatoMinePos);

    potatoMinePixmap = new QPixmap(":/Images/Potatomine.png");
    *potatoMinePixmap = potatoMinePixmap->scaledToWidth(50);

    bombTimer = new QTime;
    bombTimer->start();
}

PotatoMine::~PotatoMine()
{
    delete potatoMinePixmap;
    delete bombTimer;
}

void PotatoMine::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *potatoMinePixmap, boundingRect());
}

QRectF PotatoMine::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void PotatoMine::advance(int phase)
{
    if (!phase) return;

    QList<QGraphicsItem *> list = scene()->collidingItems(this);
    for (int i = 0; i < list.size(); i++)
    {
        Zombie *zombie = dynamic_cast<Zombie *>(list[i]);
        if (zombie)
        {
            if (bombTimer->elapsed() >= rate*1000)
            {
                exploded++;
                zombie->life -= damage;
            }
        }
    }

    // If plant explodes or life reaches 0, plant dies.
    if (exploded || life <= 0)
        delete this;
}
