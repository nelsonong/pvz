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

    // Set ui elements for most recent player.
    ui->nameLabel->setText(Player::playerName(0));   // Set name to most recent player.
    ui->levelLabel->setText(Player::playerLevel(0));  // Set level to most recent player.
    ui->comboBox->setCurrentIndex(0);    // Set combo box to most recent player.
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    // Set ui elements for selected player.
    ui->nameLabel->setText(Player::playerName(index));   // Set name to selected player.
    ui->levelLabel->setText(Player::playerLevel(index));  // Set level to selected player.

}

void MainWindow::on_newButton_clicked()
{   
    // Get player info.
    QString timestamp = QDateTime::currentDateTime().toString("dd.MM.yyyy");    // Get current date.
    QString name = QInputDialog::getText(this, "Get Name", "What's your name? ", QLineEdit::Normal, "");
    QString level = QString::number(0);
    Player::addPlayer(timestamp, name, level);

    // Change ui elements.
    ui->comboBox->insertItem(0, name);  // Insert new name to beginning of combo box.
    ui->comboBox->setCurrentIndex(0);   // Set combo box to name.
    ui->nameLabel->setText(name);   // Set nameLabel to inputted name.
    ui->levelLabel->setText("Level: " + level); // Set levelLabel to level (0 because new player).
}

void MainWindow::on_deleteButton_clicked()
{
    Player::deletePlayer(ui->comboBox->currentIndex());
    ui->comboBox->removeItem(ui->comboBox->currentIndex());
}

void MainWindow::on_startButton_clicked()
{
    Player::makeMostRecent(ui->comboBox->currentIndex());   // Move selected player in pvz_players.csv to the top (most recent).

    // Change ui elements.
    ui->comboBox->removeItem(ui->comboBox->currentIndex()); // Remove selected item.
    ui->comboBox->insertItem(0, Player::playerName(0)); // Insert it back at the top.
    ui->comboBox->setCurrentIndex(0);   // Set combo box to top.
}

void MainWindow::on_quitButton_clicked()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
