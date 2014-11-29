#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include "peashooter.h"

class GameScreen : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = 0);
    bool buttonPressed;
    QPoint grid[10][6];    // To hold grid positions.
    QPoint currentGridPoint;


private:
    void mousePressEvent(QMouseEvent *e);
    QPoint getGridPoint(QMouseEvent *e);
    PeaShooter *peaShooter;

signals:
    // Emits signal to indicate which grid position clicked.
    void click();

public slots:

};

#endif // GAMESCREEN_H
