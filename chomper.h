#ifndef CHOMPER_H
#define CHOMPER_H
#include "plant.h"
#include "zombie.h"

#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <QPoint>
#include <QTime>

class Chomper : public Plant
{
public:
    Chomper();
    Chomper(QPoint chomperPos);
    ~Chomper();
    QPixmap *chomperPixmap;
    int rectangleLength;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QGraphicsLineItem *collisionLine;
    void advance(int phase);

    QTime *eatZombie;
    QTime *zombieAttack;
};

#endif // CHOMPER_H
