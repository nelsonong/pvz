#include "sunflower.h"

SunFlower::SunFlower()
{

}

SunFlower::SunFlower(QPoint gridPoint)
{
    point = gridPoint;

    cost = 50;
    life = 4;
    range = 0;
    damage = 0;
    rate = 24;
    splash = 0;
    slow = 0;
    bomb = 0;
    seeding = 7.5;
    //sun = 1;
    need = 0;

    sunFlowerPixmap = new QPixmap(":/Images/Sunflower.png");
    *sunFlowerPixmap = sunFlowerPixmap->scaledToWidth(50);
    this->setPos(gridPoint);

    createSunTimer = new QTime;
    createSunTimer->start();
}

SunFlower::~SunFlower()
{
    delete sunFlowerPixmap;
    delete createSunTimer;
}

void SunFlower::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *sunFlowerPixmap, boundingRect());
}

QRectF SunFlower::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void SunFlower::advance(int phase)
{
    if (!phase) return;

    if (createSunTimer->elapsed() >= this->rate*1000)
    {
        createSunTimer->restart();
        sun = new Sun(point);
        scene()->addItem(sun);
    }

    // When life goes to 0, plant dies.
    if (life <= 0)
        delete this;
}
