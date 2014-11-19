#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <QInputDialog>
#include <QStringList>
#include <QString>
#include <vector>

using std::vector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile save_file("C:/Qt/Tools/QtCreator/bin/PvZ/pvz_players.csv");
    if (save_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {        
        save_file.close();
    }

}

void MainWindow::on_newButton_clicked()
{
    static int lastIndex(0);
    QFile save_file("C:/Qt/Tools/QtCreator/bin/PvZ/pvz_players.csv");
    if (save_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream text(&save_file);

        // Save data.
        QString timestamp = QDateTime::currentDateTime().toString("dd.MM.yyyy");

        QString name = QInputDialog::getText(this, "Get Name", "What's your name? ", QLineEdit::Normal, "");
        QString level = QString::number(0);
        text << timestamp << ":" << name << ":" << level << "\n";

        ui->nameLabel->setText(name);
        ui->levelLabel->setText("Level: " + level);

        ui->comboBox->addItem(name, lastIndex);
        ui->comboBox->setCurrentIndex(lastIndex);
        lastIndex++;

        save_file.close();
    }
}

void MainWindow::on_deleteButton_clicked()
{

}

void MainWindow::on_startButton_clicked()
{

}

void MainWindow::on_quitButton_clicked()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
