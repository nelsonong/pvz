#include "lawnmower.h"

LawnMower::LawnMower()
{
}

LawnMower::LawnMower(QPoint lawnMowerPos) : screenLength(631), speed(5), move(0), zombieContact(0)
{
    this->setPos(lawnMowerPos);
    xPos = lawnMowerPos.x();
    yPos = lawnMowerPos.y();
    lawnMowerPixmap = new QPixmap(":/Images/Lawnmower.png");
    *lawnMowerPixmap = lawnMowerPixmap->scaledToHeight(50);
}

LawnMower::~LawnMower()
{
    delete lawnMowerPixmap;
}

void LawnMower::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *lawnMowerPixmap, boundingRect());
}

QRectF LawnMower::boundingRect() const
{
    return QRectF(0,0,70,50);
}

void LawnMower::advance(int phase)
{
    if (!phase) return;

    QList<QGraphicsItem *> list = scene()->collidingItems(this);
    for (int i = 0; i < list.size(); i++)
    {
        Zombie *item = dynamic_cast<Zombie *>(list[i]);
        if (item)
        {
            zombieContact++;
            delete item;
        }
    }

    if (zombieContact)
    {
        if (xPos <= screenLength)
        {
            xPos += speed;
            this->setPos(xPos,yPos);
        }
        else
        {
           delete this;
        }
    }
}
