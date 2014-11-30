#ifndef SNOWPEA_H
#define SNOWPEA_H
#include "plant.h"
#include "zombie.h"
#include "bullet.h"

#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <QPoint>
#include <QTime>

class SnowPea : public Plant
{
public:
    SnowPea();
    SnowPea(QPoint snowPeaPos);
    ~SnowPea();
    QPixmap *snowPeaPixmap;
    int screenLength;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QGraphicsLineItem *collisionLine;
    void advance(int phase);

    Bullet *bullet;
    QTime *createBullet;
    QTime *zombieAttack;
};

#endif // SNOWPEA_H
