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
#include <QMessageBox>
#include <QSound>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>

#include "player.h"
#include "level.h"
#include "gamescreen.h"

#include "npc/plants/peashooter.h"
#include "npc/plants/sunflower.h"
#include "npc/plants/cherrybomb.h"
#include "npc/plants/wallnut.h"
#include "npc/plants/potatomine.h"
#include "npc/plants/snowpea.h"
#include "npc/plants/chomper.h"
#include "npc/plants/repeater.h"

#include "npc/zombies/regular.h"
#include "npc/zombies/flag.h"
#include "npc/zombies/conehead.h"
#include "npc/zombies/buckethead.h"
#include "npc/zombies/newspaper.h"

#include "npc/misc/sun.h"
#include "npc/misc/lawnmower.h"

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

    void callCreateZombies();   // Calls zombie create function (creates zombie at specified interval).

    void createZombies();       // Creates zombies whenever called.

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
    Conehead *conehead;
    Buckethead *buckethead;
    Newspaper *newspaper;

    // Miscellaneous objects.
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
    QTimer *zombieStartTimer;
    QTimer *zombieSpawnTimer;

    // Boolean checkers.
    QString plantClicked;
    bool buttonClicked;
    bool imageAdded;

    // Brown rectangles.
    QGraphicsRectItem *rect1;
    QGraphicsRectItem *rect2;
    QGraphicsRectItem *rect3;
    QGraphicsRectItem *rect4;
    void addRectsToScene();

    void deletePointers();
};

#endif // MAINWINDOW_H
