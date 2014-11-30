#include "wallnut.h"

WallNut::WallNut()
{
}

WallNut::WallNut(QPoint wallNutPos)
{
    this->life = 72;
    this->range = 0;
    this->damage = 0;
    this->rate = 0;
    this->splash = 0;
    this->slow = 0;
    this->bomb = 0;
    this->seeding = 30;
    this->sun = 0;
    this->need = 0;

    this->setPos(wallNutPos);

    wallNutPixmap = new QPixmap(":/Images/Wallnut.png");
    wallNutPixmap->scaledToWidth(50);

    zombieAttack = new QTime;
    zombieAttack->start();
}

WallNut::~WallNut()
{
    delete wallNutPixmap;
    delete zombieAttack;
}

void WallNut::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *wallNutPixmap, boundingRect());
}

QRectF WallNut::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void WallNut::advance(int phase)
{
    if (!phase) return;

    QList<QGraphicsItem *> list = scene()->collidingItems(this);
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
