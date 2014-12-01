#include "cherrybomb.h"

CherryBomb::CherryBomb()
{
}

CherryBomb::CherryBomb(QPoint cherryBombPos)
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

    this->setPos(cherryBombPos);

    cherryBombPixmap = new QPixmap(":/Images/Cherrybomb.png");
    *cherryBombPixmap = cherryBombPixmap->scaledToWidth(50);

    zombieBomb = new QTime;
    zombieBomb->start();
}

CherryBomb::~CherryBomb()
{
    delete cherryBombPixmap;
    delete zombieBomb;
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
