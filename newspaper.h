#ifndef NEWSPAPER_H
#define NEWSPAPER_H
#include "zombie.h"
#include "plant.h"
#include "bullet.h"

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include <QPoint>

class Newspaper : public Zombie
{
public:
    Newspaper();
    Newspaper(QPoint startPos);
    ~Newspaper();

private:
    QPixmap *newspaperPixmap;   // Holds image.
    double xPos;                   // Holds x-position.
    double yPos;                   // Holds y-position.
    void move();                // Moves zombie until collision with plants.

    // Virtual derived functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // NEWSPAPER_H
