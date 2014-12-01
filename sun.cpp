#include "sun.h"

bool Sun::sunClicked = false;
int Sun::sunPoints = 100;

Sun::Sun() : xPos(qrand()%560 + 20), yPos(0), sunType(1), increment(qrand()%19 + 8), timeStarted(0)
{
    this->setPos(xPos,yPos);        // Set initial position to be random along the top of graphicsView.
    sunPixmap = new QPixmap(":/Images/Sun.png");
    destroyTimer = new QTime;
}

Sun::Sun(QPoint sunFlowerPos) : sunType(2)
{
    this->setPos(sunFlowerPos);
    sunPixmap = new QPixmap(":/Images/Sun.png");
    destroyTimer = new QTime;
    destroyTimer->start();
}

Sun::~Sun()
{
    delete sunPixmap;
    delete destroyTimer;
}

void Sun::destroySun()
{
    delete this;
}

void Sun::move()
{
    if (increment > 0)        // Once increment has completely decelerated to 0, stop decelerating.
    {
        yPos += increment;    // Initial increment gets decelerated from original random amount.
        increment--;          // Decelerate by 1px every advance() call.
        this->setPos(xPos,yPos);
    }
}

void Sun::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *sunPixmap, boundingRect());
}

QRectF Sun::boundingRect() const
{
    return QRectF(0,0,62,62);   // Set boundingRect() to image size.
}

void Sun::advance(int phase)
{
    if(!phase) return;  // Only call advance() once.

    // If this is a falling sun, make it fall.
    if (sunType == 1)
        move();

    if ((increment == 0) && (!timeStarted))
    {
        // Destroy falling suns.
        destroyTimer->start();
        timeStarted++;
    }

    // If this is a sunflower's sun, delete after 7.5s.
    if (destroyTimer->elapsed() >= 7500)
        delete this;
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mousePressEvent(e);
    sunClicked = true;  // If sun has been clicked, don't automatically delete (produces errors).
    sunPoints += 25;
    delete this;
}

