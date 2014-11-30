#include "sunflower.h"

SunFlower::SunFlower()
{

}

SunFlower::SunFlower(QPoint gridPoint)
{
    point = gridPoint;

    this->life = 4;
    this->range = 0;
    this->damage = 0;
    this->rate = 24;
    this->splash = 0;
    this->slow = 0;
    this->bomb = 0;
    this->seeding = 7.5;
    this->sun = 1;
    this->need = 0;

    sunFlowerPixmap = new QPixmap(":/Images/Sunflower.png");
    sunFlowerPixmap->scaledToWidth(50);
    this->setPos(gridPoint);

    createTimer = new QTime;
    createTimer->start();
}

SunFlower::~SunFlower()
{
    delete sunFlowerPixmap;
    delete createTimer;
}

void SunFlower::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *sunFlowerPixmap, boundingRect());
}

QRectF SunFlower::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void SunFlower::advance(int phase)
{
    if(!phase) return;

    if (createTimer->elapsed() >= this->rate*1000)
    {
        createTimer->restart();
        sunItem = new Sun(point);
        scene()->addItem(sunItem);
    }

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
}
