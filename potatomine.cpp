#include "potatomine.h"

PotatoMine::PotatoMine()
{
}

PotatoMine::PotatoMine(QPoint potatoMinePos)
{
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

    zombieBomb = new QTime;
    zombieBomb->start();
}

PotatoMine::~PotatoMine()
{
    delete potatoMinePixmap;
    delete zombieBomb;
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
        Zombie *item = dynamic_cast<Zombie *>(list[i]);
        if (item)
        {
            if (zombieAttack->elapsed() >= rate*1000)
            {
                delete item;
                delete this;
            }
        }
    }

    if (life <= 0)
        delete this;
}
