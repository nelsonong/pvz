#include "regular.h"

Regular::Regular()
{

}

Regular::Regular(QPoint startPos) : xPos(400), yPos(startPos.y())
{
    this->life = 10;
    this->attack = 1;
    this->rate = 0.5;
    this->speed = 5.0;

    this->setPos(xPos, yPos);
    regularPixmap = new QPixmap(":/Images/Regular.png");
    *regularPixmap = regularPixmap->scaledToHeight(50);
}

Regular::~Regular()
{
    delete collisionRect;
}

void Regular::move()
{
    if (!(this->collidesWithItem(this)) && (xPos != 0))
    {
        xPos -= this->speed;
        this->setPos(xPos,yPos);
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

    collisionRect = new QGraphicsRectItem(this->x(), this->y(), regularPixmap->width(), regularPixmap->height());
    QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
    for (int i = 0; i < (int)list.size(); i++)
    {
        Bullet *item = dynamic_cast<Bullet *>(list.at(i));
        qDebug() << item;
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

    //qDebug() << "My health is " << this->life;

    if (this->life <= 0)
        delete this;
}
