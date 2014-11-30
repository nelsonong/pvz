#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include "plant.h"
#include "sun.h"

#include <QGraphicsItem>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsScene>
#include <QPoint>
#include <QTimer>
#include <QTime>

class SunFlower : public Plant
{
public:
    SunFlower();
    SunFlower(QPoint gridPoint);

private:
    // Variables.
    QPoint point;
    QPixmap sunFlowerPixmap;
    Sun *sunItem;
    QTime *createTimer;

    // Virtual derived functions.
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // SUNFLOWER_H
