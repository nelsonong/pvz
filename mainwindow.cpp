#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"

#include <iostream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDateTime>
#include <QDebug>
#include <QInputDialog>

Player playerObject;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < Player::playerListSize(); i++)
    {
      ui->comboBox->addItem(Player::playerName(i));
    }

    /*
    // Set ui elements for most recent player.
    ui->nameLabel->setText(Player::playerName(Player::playerListSize()));   // Set name to most recent player.
    ui->levelLabel->setText(Player::playerName(Player::playerListSize()));  // Set level to most recent player.
    ui->comboBox->setCurrentIndex(Player::playerListSize());    // Set combo box to most recent player.
    */
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{

}

void MainWindow::on_newButton_clicked()
{
    QFile save_file("C:/Qt/Tools/QtCreator/bin/PvZ/pvz_players.csv");
    if (save_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream text(&save_file);

        // Get player info.
        QString timestamp = QDateTime::currentDateTime().toString("dd.MM.yyyy");    // Get current date.
        QString name = QInputDialog::getText(this, "Get Name", "What's your name? ", QLineEdit::Normal, "");
        QString level = QString::number(0);

        // Save player info.
        text << timestamp << ":" << name << ":" << level << "\n";   // Add player info to pvz_players.csv.
        Player::addPlayer(timestamp, name, level);  // Add player info to playerList.

        // Change ui elements.
        ui->nameLabel->setText(name);   // Set nameLabel to inputted name.
        ui->levelLabel->setText("Level: "); // Set levelLabel to level (0 because new player).

        ui->comboBox->addItem(name, Player::playerListSize());  // Add name to combo box.
        ui->comboBox->setCurrentIndex(Player::playerListSize());    // Set combo box to name.

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
