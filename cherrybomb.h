#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H
#include "plant.h"
#include "zombie.h"

#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <QPoint>
#include <QTime>

class CherryBomb : public Plant
{
public:
    CherryBomb();
    CherryBomb(QPoint pos);
    ~CherryBomb();

private:
    QPixmap *cherryBombPixmap;  // Holds image.
    int gridWidth;              // One square's width.
    int gridHeight;             // One square's height.
    QTime *bombTimer;           // Executes bomb at certain time.
    QGraphicsRectItem *collisionRect;   // Detect collision within 3x3 grid.
    bool exploded;              // If plant collides with zombie, delete itself.

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // CHERRYBOMB_H
