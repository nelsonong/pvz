#ifndef CONEHEAD_H
#define CONEHEAD_H
#include "zombie.h"
#include "plant.h"
#include "bullet.h"

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QPoint>

class Conehead : public Zombie
{
public:
    Conehead();
    Conehead(QPoint startPos);
    ~Conehead();

private:
    QPixmap *coneheadPixmap;    // Holds image.
    double xPos;                   // Holds x-position.
    double yPos;                   // Holds y-position.
    void move();                // Moves zombie until collision with plants.

    // Virtual derived functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // CONEHEAD_H
