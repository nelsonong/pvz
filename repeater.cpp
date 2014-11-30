#include "repeater.h"

Repeater::Repeater()
{
}

Repeater::Repeater(QPoint repeaterPos)
{
    this->life = 4;
    this->range = 9999;
    this->damage = 2;
    this->rate = 1.5;
    this->splash = 0;
    this->slow = 0;
    this->bomb = 0;
    this->seeding = 7.5;
    this->sun = 0;
    this->need = 0;

    this->setPos(repeaterPos);

    repeaterPixmap = new QPixmap(":/Images/Repeater.png");
    repeaterPixmap->scaledToWidth(50);
    collisionLine = new QGraphicsLineItem(this->x() + 25, this->y(), this->x() + 25, screenLength);

    createBullet = new QTime;
    createBullet->start();

    zombieAttack = new QTime;
    zombieAttack->start();
}

Repeater::~Repeater()
{
    delete repeaterPixmap;
    delete collisionLine;
    delete createBullet;
    delete zombieAttack;
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
                this->life--;
                zombieAttack->restart();
            }
        }
    }

    if (this->life <= 0)
        delete this;
}
