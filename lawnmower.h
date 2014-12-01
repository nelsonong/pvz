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
    QPixmap *lawnMowerPixmap;
    int xPos;
    int yPos;
    int screenLength;
    int speed;
    bool zombieContact;

    // Virtual derived functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // LAWNMOWER_H
