#ifndef NEWSPAPER_H
#define NEWSPAPER_H
#include "zombie.h"
#include "plant.h"
#include "bullet.h"

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QPoint>

class Newspaper : public Zombie
{
public:
    Newspaper();
    Newspaper(QPoint startPos);
    ~Newspaper();
    bool slow;

private:
    QPixmap *newspaperPixmap;
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

#endif // NEWSPAPER_H
