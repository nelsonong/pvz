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
    // Zombie stats.
    Zombie();
    int life;                   // Amount of hit points.
    int attack;                 // Damage inflicted on plants.
    double rate;                // Rate of attack.
    double speed;               // Speed, subjective to advanceTimer.
    bool slowed;                // If slowed, speed /= 2.
    static bool brainsEaten;    // If true, end game.
    static int zombiesKilled;   // If == size of sequence, game won.
    QTime *attackTimer;         // Attack plants at specified interval.

    // Virtual QGraphicsItem functions.
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // ZOMBIE_H
