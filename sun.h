#ifndef Sun_H
#define Sun_H

#include <QGraphicsItem>
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QDebug>
#include <vector>
#include <QPoint>
#include <QTimer>

class Sun : public QGraphicsItem
{
public:
    Sun();
    Sun(QPoint);
    static bool sunClicked;
    static int sunPoints;
    void destroySun();
    QTimer *createTimer;
    QTimer *destroyTimer;

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
