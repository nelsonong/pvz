#ifndef POTATOMINE_H
#define POTATOMINE_H
#include "plant.h"
#include "zombie.h"

#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QList>
#include <QPoint>
#include <QTime>

class PotatoMine : public Plant
{
public:
    PotatoMine();
    PotatoMine(QPoint potatoMinePos);
    ~PotatoMine();

private:
    QPixmap *potatoMinePixmap;      // Holds image.
    QTime *bombTimer;               // Execute bomb after certain time.
    bool exploded;                  // If plant collides with zombie, delete itself.

    // Virtual QGraphicsItem functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // POTATOMINE_H
