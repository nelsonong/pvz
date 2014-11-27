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
    bool buttonPressed;
    int xPoints[10];
    int yPoints[6];

private:
    void mousePressEvent(QMouseEvent *e);

signals:
    void click11();
    void click12();
    void click13();
    void click14();
    void click15();
    void click21();
    void click22();
    void click23();
    void click24();
    void click25();
    void click31();
    void click32();
    void click33();
    void click34();
    void click35();
    void click41();
    void click42();
    void click43();
    void click44();
    void click45();

public slots:

};

#endif // GAMESCREEN_H
