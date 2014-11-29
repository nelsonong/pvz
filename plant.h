#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsItem>
#include <QPainter>

class Plant : public QGraphicsItem
{
public:
    Plant();
    int life;
    int range;
    int damage;
    int rate;
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
    virtual void advance(int phase);
};

#endif // PLANT_H
