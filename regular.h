#ifndef REGULAR_H
#define REGULAR_H
#include "zombie.h"
#include "plant.h"
#include "bullet.h"
#include "lawnmower.h"

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QDebug>

class Regular : public Zombie
{
public:
    Regular();
    Regular(QPoint startPos);
    ~Regular();

private:
    QPixmap *regularPixmap;     // Holds image.
    double xPos;                   // Holds x-position.
    double yPos;                   // Holds y-position.
    void move();                // Moves zombie until collision with plants.

    // Virtual derived functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // REGULAR_H
