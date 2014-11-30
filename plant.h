#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Plant : public QGraphicsItem
{
public:
    Plant();
    int cost;
    int life;
    int range;
    int damage;
    double rate;
    int splash;
    int slow;
    int bomb;
    int seeding;
    int sun;
    int need;

    int xPos;
    int yPos;

    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int);
};

#endif // PLANT_H
