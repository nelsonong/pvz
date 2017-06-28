#include "repeater.h"

Repeater::Repeater()
{
}

Repeater::Repeater(QPoint repeaterPos) : screenLength(631)
{
    cost = 200;
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
    *repeaterPixmap = repeaterPixmap->scaledToHeight(58);
    collisionLine = new QGraphicsLineItem(this->x() + 25, this->y()+25, screenLength, this->y()+25);

    bulletTimer = new QTime;
    bulletTimer->start();
}

Repeater::~Repeater()
{
    delete repeaterPixmap;
    delete collisionLine;
    delete bulletTimer;
}

void Repeater::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *repeaterPixmap, boundingRect());
}

QRectF Repeater::boundingRect() const
{
    return QRectF(0,0,58,58);   // Set boundingRect() to image size.
}

void Repeater::advance(int phase)
{
    if (!phase) return;

    QList<QGraphicsItem *> list = scene()->collidingItems(collisionLine);
    for (int i = 0; i < list.size(); i++)
    {
        Zombie *item = dynamic_cast<Zombie *>(list[i]);
        if (item)
        {
            if (bulletTimer->elapsed() >= rate*1000)
            {
                bullet = new Bullet(this);
                scene()->addItem(bullet);
                bulletTimer->restart();
                return;
            }
        }
    }

    if (life <= 0)
        delete this;
}
