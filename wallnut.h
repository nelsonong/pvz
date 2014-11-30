#ifndef WALLNUT_H
#define WALLNUT_H
#include "plant.h"
#include "zombie.h"

#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <QPoint>
#include <QTime>

class WallNut : public Plant
{
public:
    WallNut();
    WallNut(QPoint wallNutPos);
    ~WallNut();
    QPixmap *wallNutPixmap;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);

    QTime *zombieAttack;
};

#endif // WALLNUT_H
