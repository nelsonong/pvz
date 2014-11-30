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

    // Functions
    void destroyBullet();      // Destroy bullet within object.
    int damage;
    bool slow;

private:
    // Variables
    QPixmap bulletPixmap;
    int xPos;
    int yPos;
    int increment;          // Amount of pixels to move sun by every timeout() call (1px/60ms).
    QGraphicsRectItem *collisionRect;
    Plant *plant;

    // Functions
    void move();            // Move bullet.

    // Virtual derived functions.
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);    // Moves bullet until collision.
    void mousePressEvent(QGraphicsSceneMouseEvent *);

};

#endif // BULLET_H
