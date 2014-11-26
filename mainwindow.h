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
#include "sun.h"

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

    void on_peaShooterButton_clicked();

    void on_sunFlowerButton_clicked();

    void on_cherryBombButton_clicked();

    void on_wallNutButton_clicked();

    void on_potatoMineButton_clicked();

    void on_snowPeaButton_clicked();

    void on_chomperButton_clicked();

    void on_repeaterButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    GameScreen *gameScreen;
    Sun *sunObject;
    QPixmap *plant;

};

#endif // MAINWINDOW_H
