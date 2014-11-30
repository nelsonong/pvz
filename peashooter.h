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
    QPixmap *peaShooterPixmap;
    int screenLength;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QGraphicsLineItem *collisionLine;
    void advance(int phase);

    Bullet *bullet;
    QTime *createBullet;
    QTime *zombieAttack;
};

#endif // PEASHOOTER_H
