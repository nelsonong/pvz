#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QDebug>
#include <QInputDialog>
#include <QSound>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>

#include "player.h"
#include "gamescreen.h"
#include "sun.h"
#include "peashooter.h"
#include "sunflower.h"
#include "cherrybomb.h"
#include "wallnut.h"
#include "potatomine.h"
#include "snowpea.h"
#include "chomper.h"
#include "repeater.h"

#include "regular.h"
#include "flag.h"
#include "conehead.h"
#include "buckethead.h"
#include "newspaper.h"

#include "lawnmower.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // Button functions.
    void on_quitButton_clicked();

    void on_newButton_clicked();

    void on_startButton_clicked();

    void on_deleteButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_peaShooterButton_clicked();

    void on_sunFlowerButton_clicked();

    void on_cherryBombButton_clicked();

    void on_wallNutButton_clicked();

    void on_potatoMineButton_clicked();

    void on_snowPeaButton_clicked();

    void on_chomperButton_clicked();

    void on_repeaterButton_clicked();

    void createSun();           // Create a falling sun every 10s.

    void updateSunPoints();     // Update sun points ever 10ms.

    void updateButtons();       // Disable buttons when not enough suns.

    void addImage();            // Add plants.

private:
    // UI objects.
    Ui::MainWindow *ui;
    GameScreen *gameScreen;
    QGraphicsScene *scene;

    // Plant objects.
    PeaShooter *peaShooter;
    SunFlower *sunFlower;
    CherryBomb *cherryBomb;
    WallNut *wallNut;
    PotatoMine *potatoMine;
    SnowPea *snowPea;
    Chomper *chomper;
    Repeater *repeater;

    // Zombie objects.
    Regular *regular;
    Flag *flag;
    Conehead *conhead;
    Buckethead *buckethead;
    Newspaper *newspaper;

    // Micaellanious objects.
    Sun *sun;
    LawnMower *lawnMower;

    // Timers.
    QTimer *advanceTimer;
    QTimer *createSunTimer;
    QTimer *updateTimer;
    QTimer *peaShooterCooldownTimer;
    QTimer *sunFlowerCooldownTimer;
    QTimer *cherryBombCooldownTimer;
    QTimer *wallNutCooldownTimer;
    QTimer *potatoMineCooldownTimer;
    QTimer *snowPeaCooldownTimer;
    QTimer *chomperCooldownTimer;
    QTimer *repeaterCooldownTimer;

    // Boolean checkers.
    QString plantClicked;
    bool buttonClicked;
    bool imageAdded;
};

#endif // MAINWINDOW_H
