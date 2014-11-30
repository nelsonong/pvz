#include "potatomine.h"

PotatoMine::PotatoMine()
{
}

PotatoMine::PotatoMine(QPoint potatoMinePos)
{
    this->life = 4;
    this->range = 1;
    this->damage = 90;
    this->rate = 15;
    this->splash = 0;
    this->slow = 0;
    this->bomb = 1;
    this->seeding = 30;
    this->sun = 0;
    this->need = 0;

    this->setPos(potatoMinePos);

    potatoMinePixmap = new QPixmap(":/Images/Potatomine.png");
    potatoMinePixmap->scaledToWidth(50);

    zombieBomb = new QTime;
    zombieBomb->start();

    zombieAttack = new QTime;
    zombieAttack->start();
}

PotatoMine::~PotatoMine()
{
    delete potatoMinePixmap;
    delete zombieBomb;
    delete zombieAttack;
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
    for (int i = 0; i < (int)list.size(); i++)
    {
        Zombie *item = dynamic_cast<Zombie *>(list.at(i));
        if (item)
        {
            if (zombieAttack->elapsed() >= this->rate*1000)
            {
                delete item;
                delete this;
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
                this->life -= item->attack;
                zombieAttack->restart();
            }
        }
    }

    if (this->life <= 0)
        delete this;
}
