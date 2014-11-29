#include "plant.h"

Plant::Plant()
{
}

void Plant::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *)
{

}

QRectF Plant::boundingRect() const
{
    return QRectF(0,0,50,50);   // Set boundingRect() to image size.
}

void Plant::advance(int phase)
{

}
