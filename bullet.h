#ifndef BULLET_H
#define BULLET_H
#include "zombie.h"
#include "plant.h"

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTime>
#include <QPoint>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QList>

class Bullet : public QGraphicsItem
{
public:
    Bullet();
    Bullet(Plant *);
    ~Bullet();

    void destroyBullet();       // Destroy bullet within object.
    int damage;                 // Applies damage to colliding zombies.
    bool slow;                  // Applies slow to colliding zombies.

private:
    QPixmap *bulletPixmap;      // Holds image.
    int xPos;                   // Holds x-position.
    int yPos;                   // Holds y-position.
    int speed;                  // Amount of pixels to move sun by every timeout() call (1px/60ms).
    void move();                // Move bullet until collision with zombie.

    // Virtual QGraphicsItem functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);

};

#endif // BULLET_H
