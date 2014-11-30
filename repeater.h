#ifndef REPEATER_H
#define REPEATER_H
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

class Repeater : public Plant
{
public:
    Repeater();
    Repeater(QPoint repeaterPos);
    ~Repeater();
    QPixmap *repeaterPixmap;
    int screenLength;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QGraphicsLineItem *collisionLine;
    void advance(int phase);

    Bullet *bullet;
    QTime *createBullet;
    QTime *zombieAttack;
};

#endif // REPEATER_H
