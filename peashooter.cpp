#include "peashooter.h"

PeaShooter::PeaShooter()
{

}

PeaShooter::PeaShooter(QPoint peaShooterPos) : screenLength(631)
{
    this->life = 4;
    this->range = 9999;
    this->damage = 1;
    this->rate = 1.5;
    this->splash = 0;
    this->slow = 0;
    this->bomb = 0;
    this->seeding = 7.5;
    this->sun = 0;
    this->need = 0;

    this->setPos(peaShooterPos);

    peaShooterPixmap = new QPixmap(":/Images/Peashooter.png");
    *peaShooterPixmap = peaShooterPixmap->scaledToWidth(50);
    collisionLine = new QGraphicsLineItem(this->x() + 25, this->y(), this->x() + 25, screenLength);

    createBullet = new QTime;
    createBullet->start();

    zombieAttack = new QTime;
    zombieAttack->start();
}

PeaShooter::~PeaShooter()
{
    delete peaShooterPixmap;
    delete collisionLine;
    delete createBullet;
    delete zombieAttack;
}

void PeaShooter::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *peaShooterPixmap, boundingRect());
}

QRectF PeaShooter::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void PeaShooter::advance(int phase)
{
    if (!phase) return;

    QList<QGraphicsItem *> list = scene()->collidingItems(collisionLine);
    for (int i = 0; i < list.size(); i++)
    {
        qDebug() << "there are colliding items" << this->rate*1000;
        Zombie *item = dynamic_cast<Zombie *>(list[i]);
        qDebug() << item;
        if (!item)
        {
            if (createBullet->elapsed() >= this->rate*1000)
            {
                qDebug() << "bullet created";
                bullet = new Bullet(this);
                scene()->addItem(bullet);
                createBullet->restart();
                return;
            }
        }
    }

    list = scene()->collidingItems(this);
    for (int i = 0; i < list.size(); i++)
    {
        Zombie *item = dynamic_cast<Zombie *>(list[i]);
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
