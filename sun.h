#ifndef SUN_H
#define SUN_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QPoint>

class Sun : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Sun(QWidget *parent = 0);
    QGraphicsPixmapItem *sun;
    QGraphicsScene *scene;
    QPixmap *newSun;

private:
    QPoint sunPos;
    int xPos;
    int yPos;
    QTimer *moveTimer;
    QTimer *createTimer;
    QTimer *destroyTimer;
    void mousePressEvent(QMouseEvent *e);

signals:

public slots:
    void moveSun();
    void createSun();
    void destroySun();

};

#endif // SUN_H
