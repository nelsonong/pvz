#include "snowpea.h"

SnowPea::SnowPea()
{
}

SnowPea::SnowPea(QPoint snowPeaPos) : screenLength(631)
{
    life = 4;
    range = 9999;
    damage = 1;
    rate = 1.5;
    splash = 0;
    slow = 1;
    bomb = 0;
    seeding = 7.5;
    sun = 0;
    need = 0;

    this->setPos(snowPeaPos);

    snowPeaPixmap = new QPixmap(":/Images/Snowpea.png");
    *snowPeaPixmap = snowPeaPixmap->scaledToWidth(50);
    collisionLine = new QGraphicsLineItem(this->x() + 25, this->y()+25, screenLength, this->y()+25);

    createBullet = new QTime;
    createBullet->start();
}

SnowPea::~SnowPea()
{
    delete snowPeaPixmap;
    delete collisionLine;
    delete createBullet;
}

void SnowPea::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *snowPeaPixmap, boundingRect());
}

QRectF SnowPea::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void SnowPea::advance(int phase)
{
    if (!phase) return;

    QList<QGraphicsItem *> list = scene()->collidingItems(collisionLine);
    for (int i = 0; i < (int)list.size(); i++)
    {
        Zombie *item = dynamic_cast<Zombie *>(list.at(i));
        if (item)
        {
            if (createBullet->elapsed() >= this->rate*1000)
            {
                bullet = new Bullet(this);
                scene()->addItem(bullet);
                createBullet->restart();
                return;
            }
        }
    }

    if (this->life <= 0)
        delete this;
}
