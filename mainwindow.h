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
#include "gamescreen.h"
#include "Sun.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void updateComboBox();
    ~MainWindow();

private slots:
    void on_quitButton_clicked();

    void on_newButton_clicked();

    void on_startButton_clicked();

    void on_deleteButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void addImage11();
    void addImage12();
    void addImage13();
    void addImage14();
    void addImage15();
    void addImage21();
    void addImage22();
    void addImage23();
    void addImage24();
    void addImage25();
    void addImage31();
    void addImage32();
    void addImage33();
    void addImage34();
    void addImage35();
    void addImage41();
    void addImage42();
    void addImage43();
    void addImage44();
    void addImage45();
    void addImage51();
    void addImage52();
    void addImage53();
    void addImage54();
    void addImage55();
    void addImage61();
    void addImage62();
    void addImage63();
    void addImage64();
    void addImage65();
    void addImage71();
    void addImage72();
    void addImage73();
    void addImage74();
    void addImage75();
    void addImage81();
    void addImage82();
    void addImage83();
    void addImage84();
    void addImage85();
    void addImage91();
    void addImage92();
    void addImage93();
    void addImage94();
    void addImage95();

    void on_peaShooterButton_clicked();

    void on_sunFlowerButton_clicked();

    void on_cherryBombButton_clicked();

    void on_wallNutButton_clicked();

    void on_potatoMineButton_clicked();

    void on_snowPeaButton_clicked();

    void on_chomperButton_clicked();

    void on_repeaterButton_clicked();

    void createSun();

    void destroySun();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    GameScreen *gameScreen;
    QPixmap *plant;
    Sun *sun;
    QTimer *moveTimer;
    QTimer *createTimer;
    QTimer *destroyTimer;
};

#endif // MAINWINDOW_H
