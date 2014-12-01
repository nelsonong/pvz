#ifndef CHOMPER_H
#define CHOMPER_H
#include "plant.h"
#include "zombie.h"

#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <QPoint>
#include <QTime>

class Chomper : public Plant
{
public:
    Chomper();
    Chomper(QPoint chomperPos);
    ~Chomper();

private:
    QPixmap *chomperPixmap;             // Holds image.
    int rectangleLength;                // Holds length (one square) for collision line.
    QGraphicsLineItem *collisionLine;   // Detects collision with zombie one square away.

    // Virtual QGraphicsItem functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);

    QTime *eatTimer;
};

#endif // CHOMPER_H
