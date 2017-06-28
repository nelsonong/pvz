#include "wallnut.h"

WallNut::WallNut()
{
}

WallNut::WallNut(QPoint wallNutPos)
{
    cost = 50;
    life = 72;
    range = 0;
    damage = 0;
    rate = 0;
    splash = 0;
    slow = 0;
    bomb = 0;
    seeding = 30;
    sun = 0;
    need = 0;

    this->setPos(wallNutPos);

    wallNutPixmap = new QPixmap(":/Images/Wallnut.png");
    *wallNutPixmap = wallNutPixmap->scaledToWidth(50);
}

WallNut::~WallNut()
{
    delete wallNutPixmap;
}

void WallNut::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *wallNutPixmap, boundingRect());
}

QRectF WallNut::boundingRect() const
{
    return QRectF(0,0,50,58);   // Set boundingRect() to image size.
}

void WallNut::advance(int phase)
{
    if (!phase) return;

    // When life goes to 0, plant dies.
    if (life <= 0)
        delete this;
}
