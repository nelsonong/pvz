#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QPixmap>
#include <QTime>

class Zombie : public QGraphicsItem
{
public:
    Zombie();
    int life;
    int attack;
    double rate;
    double speed;
    bool slowed;
    static bool brainsEaten;
    QTime *attackTimer;


    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // ZOMBIE_H
