#include "buckethead.h"

Buckethead::Buckethead()
{
}

Buckethead::Buckethead(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y()), increment(50)
{
    this->life = 65;
    this->attack = 1;
    this->rate = 0.5;
    this->speed = 5;

    this->setPos(startPos);
    bucketheadPixmap = (QPixmap(":/Images/Buckethead.png")).scaledToHeight(50);
}

Buckethead::~Buckethead()
{
    delete collisionRect;
}

void Buckethead::move()
{
    if (!(this->collidesWithItem(this)) && (xPos != 0))
    {
        xPos += increment;
        increment--;
        this->setPos(xPos,yPos);
    }
}

void Buckethead::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), bucketheadPixmap, boundingRect());
}

QRectF Buckethead::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Buckethead::advance(int phase)
{
    if (!phase) return;
    move();

    collisionRect = new QGraphicsRectItem(this->x(), this->y(), bucketheadPixmap.width(), bucketheadPixmap.height());
    QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
    for (int i = 0; i < (int)list.size(); i++)
    {
        Bullet *item = dynamic_cast<Bullet *>(list.at(i));
        if (item)
        {
            this->life--;
        }
    }

    if (this->life <= 0)
        delete this;
}
