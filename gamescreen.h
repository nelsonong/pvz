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
    static QPoint grid[11][6];    // To hold grid positions.
    QPoint currentGridPoint;
    bool rectAvailable();
    bool peaShooterRect();

private:
    void mousePressEvent(QMouseEvent *e);
    QPoint getGridPoint(QMouseEvent *e);
    LawnMower *lawnMower;

signals:
    // Emits signal to indicate which grid position clicked.
    void click();

public slots:

};

#endif // GAMESCREEN_H
