#include "gamescreen.h"

GameScreen::GameScreen(QWidget *parent) :
    QGraphicsView(parent)
{

}

void GameScreen::mousePressEvent(QMouseEvent *e)
{
    qDebug() << e->pos();
}
