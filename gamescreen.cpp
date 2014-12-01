#include "gamescreen.h"

QPoint GameScreen::grid[11][6];

GameScreen::GameScreen(QWidget *parent) :
    QGraphicsView(parent)
{
    int x[] = {-20,20,95,155,215,280,345,405,470,530,605};
    int y[] = {50,135,210,290,365,445};
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            grid[i][j] = QPoint(x[i],y[j]);
        }
    }

    setMouseTracking(true);
}

GameScreen::~GameScreen()
{

}

bool GameScreen::rectAvailable()
{
    QGraphicsRectItem *collisionRect = new QGraphicsRectItem(currentGridPoint.x(),currentGridPoint.y(),50,50);
    QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
    for (int i = 0; i < list.size(); i++)
    {
        Plant *item = dynamic_cast<Plant *>(list[i]);
        if (item)
        {
            delete collisionRect;
            return false;
        }
    }

    delete collisionRect;
    return true;
}

bool GameScreen::peaShooterRect()
{
    QGraphicsRectItem *collisionRect = new QGraphicsRectItem(currentGridPoint.x(),currentGridPoint.y(),50,50);
    QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
    for (int i = 0; i < list.size(); i++)
    {
        PeaShooter *item = dynamic_cast<PeaShooter *>(list.at(i));
        if (item)
        {
            delete item;
            delete collisionRect;
            return true;
        }
    }

    delete collisionRect;
    return false;
}

void GameScreen::mousePressEvent(QMouseEvent *e)
{
    QGraphicsView::mousePressEvent(e);
    getGridPoint(e);
    click();
}

QPoint GameScreen::getGridPoint(QMouseEvent *e)
{
    for (int i = 0; i < 10; i++)
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
