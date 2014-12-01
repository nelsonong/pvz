#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include <vector>
#include "plant.h"
#include "peashooter.h"
#include "lawnmower.h"

class GameScreen : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = 0);
    ~GameScreen();

    QPoint grid[11][6];         // To hold grid positions.
    QPoint currentGridPoint;    // Returns current position clicked.
    bool rectAvailable();       // Returns whether grid selected has plant seeded or not.
    bool peaShooterRect();      // Returns whether grid contains peaShooter.

private:
    // Virtual QGraphicsView functions.
    void mousePressEvent(QMouseEvent *e);
    QPoint getGridPoint(QMouseEvent *e);

signals:
    void click();   // Emits signal which indicates screen has been clicked.

public slots:

};

#endif // GAMESCREEN_H
