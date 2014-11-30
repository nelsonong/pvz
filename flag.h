#ifndef FLAG_H
#define FLAG_H
#include "zombie.h"
#include "plant.h"
#include "bullet.h"

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QPoint>

class Flag : public Zombie
{
public:
    Flag();
    Flag(QPoint startPos);
    ~Flag();

private:
    QPixmap *flagPixmap;
    int xPos;
    int yPos;
    void move();

    // Virtual derived functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // FLAG_H
