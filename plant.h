#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Plant : public QGraphicsItem
{
public:
    Plant();

    //  Plant stats.
    int cost;           // Cost to seed plant.
    int life;           // Hit points.
    int range;          // Range within which its attack is executed.
    int damage;         // Damage of attacks.
    double rate;        // Attack interval.
    int splash;         // Amount of n x n squares to destroy.
    bool slow;          // If true, shoots bullets that slow zombies.
    bool bomb;          // If true, destroys itself when attacking zombie.
    static int seeding; // Amount of time between seed plant.
    bool sun;           // If true, produces sun.
    bool need;          // Needs another plant to be created.

private:
    // Virtual QGraphicsItem functions.
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int);
};

#endif // PLANT_H
