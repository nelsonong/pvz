#include "sun.h"

bool Sun::sunClicked = false;
int Sun::sunPoints = 1000;

Sun::Sun() : xPos(qrand()%560 + 20), yPos(0), yEndPos(qrand()%361 + 50), sunType(1), speed(5), timeStarted(0)
{
    this->setPos(xPos,yPos);        // Set initial position to be random along the top of graphicsView.

    sunPixmap = new QPixmap(":/Images/Sun.png");
    *sunPixmap = sunPixmap->scaledToWidth(50);

    destroySunTimer = new QTime;
}

Sun::Sun(QPoint sunFlowerPos) : sunType(2)
{
    this->setPos(sunFlowerPos);

    sunPixmap = new QPixmap(":/Images/Sun.png");
    *sunPixmap = sunPixmap->scaledToWidth(50);

    destroySunTimer = new QTime;
    destroySunTimer->start();
}

Sun::~Sun()
{
    delete sunPixmap;
    delete destroySunTimer;
}

void Sun::move()
{
    if (yPos < yEndPos)        // Once speed has completely decelerated to 0, stop decelerating.
    {
        yPos += speed;    // Initial speed gets decelerated from original random amount.
        this->setPos(xPos,yPos);
    }
}

void Sun::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), *sunPixmap, boundingRect());
}

QRectF Sun::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void Sun::advance(int phase)
{
    if(!phase) return;

    // If this is a falling sun, move sun.
    if (sunType == 1)
        move();

    // When speed reaches zero, start timer to delete sun.
    if ((yPos >= yEndPos) && (!timeStarted))
    {
        destroySunTimer->start();
        timeStarted++;
    }

    // If this is a sunflower's sun, start delete timer right away.
    if (destroySunTimer->elapsed() >= 7500)
        delete this;
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mousePressEvent(e);
    sunClicked = true;  // If sun has been clicked, don't automatically delete (produces errors).
    sunPoints += 25;
    delete this;
}

