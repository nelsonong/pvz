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

    static bool sunClicked; // Makes sure sun isn't deleted twice after clicked.
    static int sunPoints;   // Monitors sun points gained.

private:
    QPixmap *sunPixmap;     // Holds image.
    int xPos;               // Holds falling sun's x-position (random).
    int yPos;               // Holds falling sun's y-position.
    int yEndPos;            // Generates a random position between top and bottom screen.
    int sunType;            // Holds sun type: falling sun = 1, sunflower sun = 2.
    int speed;              // Amount of pixels to move sun by every timeout() call (1px/50ms).
    bool timeStarted;       //
    QTime *destroySunTimer;    // Destroy sunflower sun every 7.5s.

    void move();            // Move falling sun.

    // Virtual QGraphicsItem functions.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);    // Moves falling sun and destroys sunflower sun.
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
};

#endif // SUN_H
