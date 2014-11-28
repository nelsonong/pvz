#include "gamescreen.h"

GameScreen::GameScreen(QWidget *parent) :
    QGraphicsView(parent)
{
    int xpoints[] = {20,95,155,215,280,345,405,470,530,605};
    for (int i = 0; i < 10; i++)
    {
        xPoints[i] = xpoints[i];
    }

    int ypoints[] = {50,135,210,290,365,445};
    for (int i = 0; i < 6; i++)
    {
        yPoints[i] = ypoints[i];
    }
}

void GameScreen::mousePressEvent(QMouseEvent *e)
{
    if (buttonPressed)
    {
        if (e->x() >= xPoints[0] && e->x() < xPoints[1] && e->y() >= yPoints[0] && e->y() < yPoints[1])
            click11();
        else if (e->x() >= xPoints[0] && e->x() < xPoints[1] && e->y() >= yPoints[1] && e->y() < yPoints[2])
            click12();
        else if (e->x() >= xPoints[0] && e->x() < xPoints[1] && e->y() >= yPoints[2] && e->y() < yPoints[3])
            click13();
        else if (e->x() >= xPoints[0] && e->x() < xPoints[1] && e->y() >= yPoints[3] && e->y() < yPoints[4])
            click14();
        else if (e->x() >= xPoints[0] && e->x() < xPoints[1] && e->y() >= yPoints[4] && e->y() < yPoints[5])
            click15();
        else if (e->x() >= xPoints[1] && e->x() < xPoints[2] && e->y() >= yPoints[0] && e->y() < yPoints[1])
            click21();
        else if (e->x() >= xPoints[1] && e->x() < xPoints[2] && e->y() >= yPoints[1] && e->y() < yPoints[2])
            click22();
        else if (e->x() >= xPoints[1] && e->x() < xPoints[2] && e->y() >= yPoints[2] && e->y() < yPoints[3])
            click23();
        else if (e->x() >= xPoints[1] && e->x() < xPoints[2] && e->y() >= yPoints[3] && e->y() < yPoints[4])
            click24();
        else if (e->x() >= xPoints[1] && e->x() < xPoints[2] && e->y() >= yPoints[4] && e->y() < yPoints[5])
            click25();
        else if (e->x() >= xPoints[2] && e->x() < xPoints[3] && e->y() >= yPoints[0] && e->y() < yPoints[1])
            click31();
        else if (e->x() >= xPoints[2] && e->x() < xPoints[3] && e->y() >= yPoints[1] && e->y() < yPoints[2])
            click32();
        else if (e->x() >= xPoints[2] && e->x() < xPoints[3] && e->y() >= yPoints[2] && e->y() < yPoints[3])
            click33();
        else if (e->x() >= xPoints[2] && e->x() < xPoints[3] && e->y() >= yPoints[3] && e->y() < yPoints[4])
            click34();
        else if (e->x() >= xPoints[2] && e->x() < xPoints[3] && e->y() >= yPoints[4] && e->y() < yPoints[5])
            click35();
        else if (e->x() >= xPoints[3] && e->x() < xPoints[4] && e->y() >= yPoints[0] && e->y() < yPoints[1])
            click41();
        else if (e->x() >= xPoints[3] && e->x() < xPoints[4] && e->y() >= yPoints[1] && e->y() < yPoints[2])
            click42();
        else if (e->x() >= xPoints[3] && e->x() < xPoints[4] && e->y() >= yPoints[2] && e->y() < yPoints[3])
            click43();
        else if (e->x() >= xPoints[3] && e->x() < xPoints[4] && e->y() >= yPoints[3] && e->y() < yPoints[4])
            click44();
        else if (e->x() >= xPoints[3] && e->x() < xPoints[4] && e->y() >= yPoints[4] && e->y() < yPoints[5])
            click45();
        buttonPressed = 0;
    }
}
