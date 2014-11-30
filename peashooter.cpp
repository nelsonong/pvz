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
