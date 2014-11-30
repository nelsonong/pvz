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

class PeaShooter : public Plant
{
public:
    PeaShooter();
    PeaShooter(QPoint peaShooterPos);
    ~PeaShooter();
    QPixmap peaShooterPixmap;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QGraphicsLineItem *collisionLine;
    QGraphicsItem *zombieToShoot;
    void advance(int phase);
    Bullet *bullet;
    QTime *createBullet;
};

#endif // PEASHOOTER_H
