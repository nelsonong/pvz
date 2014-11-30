#ifndef SUN_H
#define SUN_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QDebug>
#include <vector>
#include <QPoint>
#include <QTime>

class Sun : public QGraphicsItem
{
public:
    Sun();                  // Sun type 1 (falling sun).
    Sun(QPoint point);      // Sun type 2 (sunflower sun).
    ~Sun();

    // Variables.
    static bool sunClicked; // Makes sure sun isn't deleted twice after clicked.
    static int sunPoints;   // Monitors sun points gained.

    // Functions
    void destroySun();      // Destroy sun within object.

private:
    // Variables
    QPixmap *sunPixmap;
    int xPos;               // Falling sun's random x-position.
    int yPos;               // Falling sun's moving y-position.
    int sunType;            // Falling sun(type-1) or sunflower sun(type-2).
    int increment;          // Amount of pixels to move sun by every timeout() call (1px/60ms).
    bool timeStarted;
    QTime *destroyTimer;    // Destroy sunflower sun every 7.5s.

    // Functions
    void move();            // Move falling sun.

    // Virtual derived functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);    // Moves falling sun and destroys sunflower sun.
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
};

#endif // SUN_H
