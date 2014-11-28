#ifndef Sun_H
#define Sun_H

#include <QGraphicsItem>
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QDebug>

class Sun : public QGraphicsItem
{
public:
    Sun();
    static bool sunClicked;
    static int sunPoints;

private:
    QPixmap sunPixmap;
    int xPos;
    int yPos;
    int pixelsMoved;
    void move();
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    void advance(int phase);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
};

#endif // Sun_H
