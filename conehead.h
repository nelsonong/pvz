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
    QPixmap *coneheadPixmap;
    int xPos;
    int yPos;
    void move();

    // Virtual derived functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // CONEHEAD_H
