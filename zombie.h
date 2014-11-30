#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class Zombie : public QGraphicsItem
{
public:
    Zombie();
    int life;
    int attack;
    double rate;
    double speed;

    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int);
};

#endif // ZOMBIE_H
