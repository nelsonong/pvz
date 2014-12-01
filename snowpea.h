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

private:
    QPixmap *snowPeaPixmap;             // Holds image.
    int screenLength;                   // Holds graphicsView length.
    Bullet *bullet;                     // Bullet QGraphicsItem.
    QTime *bulletTimer;                 // Shoot bullet after certain time.
    QGraphicsLineItem *collisionLine;   // Monitors when zombie is in the same lane.

    // Virtual QGraphicsItem functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // SNOWPEA_H
