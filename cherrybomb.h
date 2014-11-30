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
    CherryBomb(QPoint cherryBombPos);
    ~CherryBomb();
    QPixmap *cherryBombPixmap;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);

    QTime *zombieBomb;
    QTime *zombieAttack;

};

#endif // CHERRYBOMB_H
