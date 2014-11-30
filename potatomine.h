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
    QPixmap *potatoMinePixmap;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);

    QTime *zombieBomb;
    QTime *zombieAttack;
};

#endif // POTATOMINE_H
