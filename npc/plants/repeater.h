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

private:
    QPixmap *repeaterPixmap;            // Holds image.
    int screenLength;                   // Holds graphicsView length.
    Bullet *bullet;                     // Bullet QGraphicsItem.
    QTime *bulletTimer;                 // Shoot bullet after certain time.
    QGraphicsLineItem *collisionLine;   // Monitors when zombie is in the same lane.

    // Virtual QGraphicsItem functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;

    void advance(int phase);


};

#endif // REPEATER_H
