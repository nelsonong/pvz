#include "newspaper.h"

Newspaper::Newspaper()
{
}

Newspaper::Newspaper(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y()), increment(50)
{
    this->life = 16;
    this->attack = 1;
    this->rate = 0.5;
    this->speed = 5;

    this->setPos(startPos);
    newspaperPixmap = new QPixmap(":/Images/Newspaper.png");
    newspaperPixmap->scaledToHeight(50);
}

Newspaper::~Newspaper()
{
    delete collisionRect;
}

void Newspaper::move()
{
    if (!(this->collidesWithItem(this)) && (xPos != 0))
    {
        xPos -= this->speed;
        this->setPos(xPos,yPos);
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

    collisionRect = new QGraphicsRectItem(this->x(), this->y(), newspaperPixmap->width(), newspaperPixmap->height());
    QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
    for (int i = 0; i < (int)list.size(); i++)
    {
        Bullet *item = dynamic_cast<Bullet *>(list.at(i));
        if (item)
        {
            this->life -= item->damage;
            if (item->slow && !this->slow)
            {
                this->speed /= 2;
                this->slow++;
            }
        }
    }

    if (this->life <= 8)
    {
        delete newspaperPixmap;
        newspaperPixmap = new QPixmap(":/Images/Regular.png");
        this->speed = 2;
    }

    if (this->life <= 0)
        delete this;
}
