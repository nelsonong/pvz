#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <vector>
#include <QFile>
#include <QTextStream>
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

    // Sun functions.
    void createSun();
    void createSunFlowerSun();
    void destroySun();
    void destroySunFlowerSun();
    void updateSunPoints();

    // Add plant functions.
    void addImage();

private:
    // UI variables.
    Ui::MainWindow *ui;
    GameScreen *gameScreen;
    QGraphicsScene *scene;

    // Objects to be put in UI.
    QPixmap *plant;
    Sun *sun;
    Sun *sunFlowerSun;
    std::vector<Plant*> plantObjects;
    PeaShooter *peaShooter;
    SunFlower *sunFlower;

    // Timers.
    QTimer *moveTimer;
    QTimer *createTimer;
    QTimer *destroyTimer;
    QTimer *updateSunPointsTimer;

    QString plantClicked;
    bool buttonClicked;
    bool imageAdded;
};

#endif // MAINWINDOW_H
