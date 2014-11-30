#ifndef BUCKETHEAD_H
#define BUCKETHEAD_H
#include "zombie.h"
#include "plant.h"
#include "bullet.h"

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QPoint>

class Buckethead : public Zombie
{
public:
    Buckethead();
    Buckethead(QPoint startPos);
    ~Buckethead();
    bool slow;

private:
    QPixmap *bucketheadPixmap;
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

#endif // BUCKETHEAD_H
