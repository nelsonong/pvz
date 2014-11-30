#ifndef REGULAR_H
#define REGULAR_H
#include "zombie.h"
#include "plant.h"
#include "bullet.h"

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QPoint>

class Regular : public Zombie
{
public:
    Regular();
    Regular(QPoint startPos);
    ~Regular();

private:
    Zombie zombieObject;
    QPixmap regularPixmap;
    int xPos;
    int yPos;
    int increment;
    void move();
    QGraphicsRectItem *collisionRect;

    // Virtual derived functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // REGULAR_H
