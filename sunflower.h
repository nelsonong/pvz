#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include "plant.h"
#include "sun.h"
#include "zombie.h"

#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QPoint>
#include <QTimer>
#include <QTime>

class SunFlower : public Plant
{
public:
    SunFlower();
    SunFlower(QPoint gridPoint);
    ~SunFlower();

private:
    QPoint point;
    QPixmap *sunFlowerPixmap;       // Holds image.
    Sun *sun;                       // Sun QGraphicsItem.
    QTime *createSunTimer;          // Creates sun at specified intervals.

    // Virtual QGraphicsItem functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // SUNFLOWER_H
