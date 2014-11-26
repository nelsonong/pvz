#include "gamescreen.h"

GameScreen::GameScreen(QWidget *parent) :
    QGraphicsView(parent)
{

}

void GameScreen::mousePressEvent(QMouseEvent *e)
{
    mousePos = e->pos();
    if (e->x() >= 20 && e->x() < 95 && e->y() >= 50 && e->y() < 135)
        click11();
    else if (e->x() >= 20 && e->x() < 95 && e->y() >= 135 && e->y() < 210)
        click12();
    else if (e->x() >= 20 && e->x() < 95 && e->y() >= 210 && e->y() < 290)
        click13();
    else if (e->x() >= 20 && e->x() < 95 && e->y() >= 290 && e->y() < 365)
        click14();
    else if (e->x() >= 20 && e->x() < 95 && e->y() >= 365 && e->y() < 445)
        click15();
    else if (e->x() >= 95 && e->x() < 155 && e->y() >= 50 && e->y() < 135)
        click21();
    else if (e->x() >= 95 && e->x() < 155 && e->y() >= 135 && e->y() < 210)
        click22();
    else if (e->x() >= 95 && e->x() < 155 && e->y() >= 210 && e->y() < 290)
        click23();
    else if (e->x() >= 95 && e->x() < 155 && e->y() >= 290 && e->y() < 365)
        click24();
    else if (e->x() >= 95 && e->x() < 155 && e->y() >= 365 && e->y() < 445)
        click25();
    else if (e->x() >= 155 && e->x() < 215 && e->y() >= 50 && e->y() < 135)
        click31();
    else if (e->x() >= 155 && e->x() < 215 && e->y() >= 135 && e->y() < 210)
        click32();
    else if (e->x() >= 155 && e->x() < 215 && e->y() >= 210 && e->y() < 290)
        click33();
    else if (e->x() >= 155 && e->x() < 215 && e->y() >= 290 && e->y() < 365)
        click34();
    else if (e->x() >= 155 && e->x() < 215 && e->y() >= 365 && e->y() < 445)
        click35();

    qDebug() << e->pos();
}
