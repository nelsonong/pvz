#ifndef PEASHOOTER_H
#define PEASHOOTER_H
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
#include <QDebug>

class PeaShooter : public Plant
{
public:
    PeaShooter();
    PeaShooter(QPoint peaShooterPos);
    ~PeaShooter();

private:
    QPixmap *peaShooterPixmap;          // Holds image.
    int screenLength;                   // Holds graphicsView length.
    Bullet *bullet;                     // Bullet QGraphicsItem.
    QTime *bulletTimer;                 // Shoot bullet after certain time.
    QGraphicsLineItem *collisionLine;   // Monitors when zombie is in the same lane.

    // Virtual QGraphicsItem functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // PEASHOOTER_H
