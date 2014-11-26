#include "sun.h"

Sun::Sun(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setSceneRect(0,0,50,50);
    //scene->setSceneRect(0,0,50,50);
    newSun = new QPixmap(":/Images/Sun.png");
    //QGraphicsPixmapItem *pm =
            //scene->addPixmap(*newSun);

    /*
    // Don't forget to softcode.
    sunPos.setX(0);
    sunPos.setY(rand()%630);

    pm->setPos(sunPos);
    this->setScene(scene);
*/
    // Every 1 second change position.
    moveTimer = new QTimer;
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveSun()));
    moveTimer->start(1000);

    // Every 10 seconds create sun.
    createTimer = new QTimer;
    connect(createTimer, SIGNAL(timeout()), this, SLOT(moveSun()));
    createTimer->start(10000);

    // Every 7.5 seconds destroy sun.
    destroyTimer = new QTimer;
    connect(destroyTimer, SIGNAL(timeout()), this, SLOT(destroySun()));
    destroyTimer->start(7500);
}

void Sun::mousePressEvent(QMouseEvent *e)
{
    e->pos();
}

void Sun::moveSun()
{
    static int x = 0;
    sunPos.setX(x);
    x += 100;
}

void Sun::createSun()
{
    newSun = new QPixmap(":/Images/Sun.png");
}

void Sun::destroySun()
{
    delete newSun;
}
