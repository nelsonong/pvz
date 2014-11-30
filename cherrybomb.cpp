#include "cherrybomb.h"

CherryBomb::CherryBomb()
{
}

CherryBomb::CherryBomb(QPoint cherryBombPos)
{
    this->life = 4;
    this->range = 1;
    this->damage = 150;
    this->rate = 42;
    this->splash = 0;
    this->slow = 0;
    this->bomb = 0;
    this->seeding = 7.5;
    this->sun = 0;
    this->need = 0;

    this->setPos(cherryBombPos);

    cherryBombPixmap = new QPixmap(":/Images/Cherrybomb.png");
    cherryBombPixmap->scaledToWidth(50);

    zombieBomb = new QTime;
    zombieBomb->start();

    zombieAttack = new QTime;
    zombieAttack->start();
}

CherryBomb::~CherryBomb()
{
    delete cherryBombPixmap;
    delete zombieBomb;
    delete zombieAttack;
}

void CherryBomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *cherryBombPixmap, boundingRect());
}

QRectF CherryBomb::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void CherryBomb::advance(int phase)
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
                this->life--;
                zombieAttack->restart();
            }
        }
    }

    if (this->life <= 0)
        delete this;
}
