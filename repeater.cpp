#include "repeater.h"

Repeater::Repeater()
{
}

Repeater::Repeater(QPoint repeaterPos)
{
    life = 4;
    range = 9999;
    damage = 2;
    rate = 1.5;
    splash = 0;
    slow = 0;
    bomb = 0;
    seeding = 7.5;
    sun = 0;
    need = 0;

    this->setPos(repeaterPos);

    repeaterPixmap = new QPixmap(":/Images/Repeater.png");
    *repeaterPixmap = repeaterPixmap->scaledToWidth(50);
    collisionLine = new QGraphicsLineItem(this->x() + 25, this->y()+25, screenLength, this->y()+25);

    createBullet = new QTime;
    createBullet->start();
}

Repeater::~Repeater()
{
    delete repeaterPixmap;
    delete collisionLine;
    delete createBullet;
}

void Repeater::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *repeaterPixmap, boundingRect());
}

QRectF Repeater::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void Repeater::advance(int phase)
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
