#include "cherrybomb.h"

CherryBomb::CherryBomb()
{
}

CherryBomb::CherryBomb(QPoint pos) : gridWidth(60), gridHeight(70), exploded(0)
{
    cost = 150;
    life = 9999;
    range = 1;
    damage = 90;
    rate = 1;
    splash = 3;
    slow = 0;
    bomb = 1;
    seeding = 50;
    sun = 0;
    need = 0;

    this->setPos(pos);

    cherryBombPixmap = new QPixmap(":/Images/Cherrybomb.png");
    *cherryBombPixmap = cherryBombPixmap->scaledToWidth(50);

    bombTimer = new QTime;
    bombTimer->start();

    collisionRect = new QGraphicsRectItem(this->x()-gridWidth, this->y()-gridHeight,3*gridWidth, 3*gridHeight);
}

CherryBomb::~CherryBomb()
{
    delete cherryBombPixmap;
    delete bombTimer;
    delete collisionRect;
}

void CherryBomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *cherryBombPixmap, boundingRect());
}

QRectF CherryBomb::boundingRect() const
{
    // Set bounding rect to top-left point and bottom-right point of 3x3 grid.
    return QRectF(0, 0, cherryBombPixmap->width(), cherryBombPixmap->height());
}

void CherryBomb::advance(int phase)
{
    if (!phase) return;

    QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
    for (int i = 0; i < list.size(); i++)
    {
        Zombie *zombie = dynamic_cast<Zombie *>(list[i]);
        if (zombie)
        {
            if (bombTimer->elapsed() >= rate*1000)
            {
                exploded++;                 // True if exploded.
                zombie->life -= damage;     // Destroy all zombies within its vicinity.
            }
        }
    }

    if (bombTimer->elapsed() >= rate*1000)
        life -= 9999;

    // If plant explodes or life reaches 0, plant dies.
    if (exploded || life <= 0)
        delete this;
}
