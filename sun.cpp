#include "Sun.h"

bool Sun::sunClicked = false;
Sun::Sun() : xPos(qrand()%560 + 20), yPos(0), pixelsMoved(qrand()%19 + 8)
{
    this->setPos(xPos,yPos);        // Set initial position to be random along the top.
    sunPixmap = QPixmap(":/Images/Sun.png");
}

void Sun::move()
{
    if (pixelsMoved > 0)        // Once pixelsMoved has completely decelerated to 0, stop decelerating.
    {
        yPos += pixelsMoved;    // Initial pixelsMoved gets decelerated from original random amount.
        pixelsMoved--;          // Decelerate by 1px every advance() call.
        this->setPos(xPos,yPos);
    }
}

void Sun::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(),sunPixmap, boundingRect());
}

QRectF Sun::boundingRect() const
{
    return QRectF(0,0,62,62);   // Set boundingRect() to image size.
}

void Sun::advance(int phase)
{
    if(!phase) return;  // Only call advance() once.
    move();
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    sunClicked = true;  // If sun has been clicked, don't automatically delete (produces errors).
    sunPoints += 25;
    delete this;
}
