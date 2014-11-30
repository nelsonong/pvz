#include "gamescreen.h"

GameScreen::GameScreen(QWidget *parent) :
    QGraphicsView(parent)
{
    int x[] = {20,95,155,215,280,345,405,470,530,605};
    int y[] = {50,135,210,290,365,445};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            grid[i][j] = QPoint(x[i],y[j]);
        }
    }

    setMouseTracking(true);
}

void GameScreen::mousePressEvent(QMouseEvent *e)
{
    QGraphicsView::mousePressEvent(e);
    getGridPoint(e);
    click();
}

QPoint GameScreen::getGridPoint(QMouseEvent *e)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (e->x() >= grid[i][j].x() && e->x() < grid[i+1][j].x() && e->y() >= grid[i][j].y() && e->y() < grid[i][j+1].y())
            {
                currentGridPoint = grid[i][j];
                return grid[i][j];
            }
        }
    }
    return QPoint(0,0);
}
