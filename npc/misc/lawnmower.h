#ifndef LAWNMOWER_H
#define LAWNMOWER_H
#include "zombie.h"

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QPoint>

class LawnMower : public QGraphicsItem
{
public:
    LawnMower();
    LawnMower(QPoint lawnMowerPos);
    ~LawnMower();
    bool move;

private:
    QPixmap *lawnMowerPixmap;       // Holds image.
    int xPos;                       // Holds x-coordinate.
    int yPos;                       // Holds y-coordinate.
    int screenLength;               // Deletes lawn mower when out of screen length.
    int speed;                      // Holds lawn mower speed.
    bool zombieCollide;             // When zombie collides, move lawn mower.s

    // Virtual derived functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // LAWNMOWER_H
