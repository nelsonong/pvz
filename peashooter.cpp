#include "peashooter.h"

PeaShooter::PeaShooter()
{

}

PeaShooter::PeaShooter(QPoint peaShooterPos)
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

    peaShooterPixmap = (QPixmap(":/Images/Peashooter.png")).scaledToWidth(50);
    collisionLine = new QGraphicsLineItem(this->x() + 25, this->y(), this->x() + 25, 700);  // 700 = end of screen.
    createBullet = new QTime;
    createBullet->start();
}

PeaShooter::~PeaShooter()
{
    delete collisionLine;
    delete createBullet;
}

void PeaShooter::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), peaShooterPixmap, boundingRect());
}

QRectF PeaShooter::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void PeaShooter::advance(int phase)
{
    if (!phase) return;

    if (createBullet->elapsed() >= 1500)
    {
        QList<QGraphicsItem *> list = scene()->collidingItems(collisionLine);
        for (int i = 0; i < (int)list.size(); i++)
        {
            Zombie *item = dynamic_cast<Zombie *>(list.at(i));
            if (item)
            {
                bullet = new Bullet(this);
                scene()->addItem(bullet);
                return;
            }
        }
        createBullet->restart();
    }
}
