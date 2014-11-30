#include "newspaper.h"

Newspaper::Newspaper()
{
}

Newspaper::Newspaper(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y())
{
    this->life = 16;
    this->attack = 1;
    this->rate = 0.5;
    this->speed = 1.0;
    this->slowed = 0;

    this->setPos(startPos);
    newspaperPixmap = new QPixmap(":/Images/Newspaper.png");
    *newspaperPixmap = newspaperPixmap->scaledToHeight(50);

    this->zombieAttack = new QTime;
    this->zombieAttack->start();

    collisionRect = new QGraphicsRectItem(this->x(), this->y(), newspaperPixmap->width(), newspaperPixmap->height());
}

Newspaper::~Newspaper()
{
    delete this->zombieAttack;
    delete collisionRect;
}

void Newspaper::move()
{
    if (xPos != 0)
    {
        collisionRect->setRect(this->x(),this->y(),newspaperPixmap->width(),newspaperPixmap->height());
        QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
        for (int i = 0; i < list.size(); i++)
        {
            Plant *item = dynamic_cast<Plant *>(list.at(i));
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

void Newspaper::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *newspaperPixmap, boundingRect());
}

QRectF Newspaper::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Newspaper::advance(int phase)
{
    if (!phase) return;
    move();

    if (this->life <= 8)
    {
        delete newspaperPixmap;
        newspaperPixmap = new QPixmap(":/Images/Regular.png");
        this->speed = 2;
    }

    if (this->life <= 0)
        delete this;
}
