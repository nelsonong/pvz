#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>

class GameScreen : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = 0);
    QPoint mousePos;

private:
    void mousePressEvent(QMouseEvent *e);

public slots:

};

#endif // GAMESCREEN_H
