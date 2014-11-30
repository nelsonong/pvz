#include "regular.h"

Regular::Regular()
{

}

Regular::Regular(QPoint startPos) : xPos(400), yPos(startPos.y())
{
    this->life = 10;
    this->attack = 1;
    this->rate = 0.5;
    this->speed = 1.0;

    this->setPos(xPos, yPos);
    regularPixmap = new QPixmap(":/Images/Regular.png");
    *regularPixmap = regularPixmap->scaledToHeight(50);

    this->zombieAttack = new QTime;
    this->zombieAttack->start();

    this->collisionRect = new QGraphicsRectItem(this->x(), this->y(), regularPixmap->width(), regularPixmap->height());
}

Regular::~Regular()
{
    delete this->zombieAttack;
    delete this->collisionRect;
}

void Regular::move()
{
    if (xPos != 0)
    {
        collisionRect->setRect(this->x(),this->y(),regularPixmap->width(),regularPixmap->height());
        QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
        for (int i = 0; i < list.size(); i++)
        {
            Plant *item = dynamic_cast<Plant *>(list.at(i));
            qDebug() << item;
            if (item)
            {
               item->life -= this->attack;
               return;
            }
        }

        xPos -= this->speed;
        this->setPos(xPos,yPos);
    }
    else
    {
       Zombie::brainsEaten = true;
    }
}

void Regular::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *regularPixmap, boundingRect());
}

QRectF Regular::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Regular::advance(int phase)
{
    if (!phase) return;
    move();

    if (this->life <= 0)
        delete this;
}
