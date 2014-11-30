#include "conehead.h"

Conehead::Conehead()
{
}

Conehead::Conehead(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y()), increment(50)
{
    this->life = 28;
    this->attack = 1;
    this->rate = 0.5;
    this->speed = 5;

    this->setPos(startPos);
    coneheadPixmap = new QPixmap(":/Images/Conehead.png");
    *coneheadPixmap = coneheadPixmap->scaledToHeight(50);
}

Conehead::~Conehead()
{
    delete collisionRect;
}

void Conehead::move()
{
    if (!(this->collidesWithItem(this)) && (xPos != 0))
    {
        xPos -= this->speed;
        this->setPos(xPos,yPos);
    }
}

void Conehead::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *coneheadPixmap, boundingRect());
}

QRectF Conehead::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Conehead::advance(int phase)
{
    if (!phase) return;
    move();

    collisionRect = new QGraphicsRectItem(this->x(), this->y(), coneheadPixmap->width(), coneheadPixmap->height());
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

    if (this->life <= 10)
    {
        delete coneheadPixmap;
        coneheadPixmap = new QPixmap(":/Images/Regular.png");
    }

    if (this->life <= 0)
        delete this;
}
