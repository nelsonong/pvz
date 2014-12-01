#include "peashooter.h"

PeaShooter::PeaShooter()
{

}

PeaShooter::PeaShooter(QPoint peaShooterPos) : screenLength(631)
{
    life = 4;
    range = 9999;
    damage = 1;
    rate = 1.5;
    splash = 0;
    slow = 0;
    bomb = 0;
    seeding = 7.5;
    sun = 0;
    need = 0;

    this->setPos(peaShooterPos);

    peaShooterPixmap = new QPixmap(":/Images/Peashooter.png");
    *peaShooterPixmap = peaShooterPixmap->scaledToWidth(50);
    collisionLine = new QGraphicsLineItem(this->x() + 25, this->y()+25, screenLength, this->y()+25);

    createBullet = new QTime;
    createBullet->start();
}

PeaShooter::~PeaShooter()
{
    delete peaShooterPixmap;
    delete collisionLine;
    delete createBullet;
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
        Zombie *item = dynamic_cast<Zombie *>(list[i]);
        qDebug() << item;
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
