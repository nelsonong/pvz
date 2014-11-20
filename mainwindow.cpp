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

    if (Player::validPlayerFile())
    {
        for (int i = 0; i < Player::playerListSize(); i++)
        {
          ui->comboBox->addItem(Player::playerName(i)); // Add existing players to comboBox.
        }

        // Set ui elements for most recent player.
        ui->nameLabel->setText(Player::playerName(0));   // Set name to most recent player.
        ui->levelLabel->setText(Player::playerLevel(0));  // Set level to most recent player.
        ui->comboBox->setCurrentIndex(0);    // Set comboBox to most recent player.
    }
    else
    {
        Player::clearPlayerList();  // Discard current file.

        // Set ui elements for if no players exist.
        ui->nameLabel->setText("");   // Delete player name.
        ui->levelLabel->setText("");  // Delete player level.

        // Disable buttons if no players.
        ui->startButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
        ui->restartButton->setEnabled(false);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    // Set ui elements for selected player.
    ui->nameLabel->setText(Player::playerName(index));   // Set name to selected player.
    ui->levelLabel->setText(Player::playerLevel(index));  // Set level to selected player.

}

void MainWindow::on_newButton_clicked()
{       
    // Add player info.
    QString timestamp = QDateTime::currentDateTime().toString("MM.dd.yyyy");    // Get current date.
    QString name = QInputDialog::getText(this, "Get Name", "What's your name? ", QLineEdit::Normal, "");
    QString level = QString::number(1); // Default: level 1.
    Player::addPlayer(timestamp, name, level);  // Add player to playerList.

    // Change ui elements.
    ui->comboBox->insertItem(0, name);  // Insert new name to beginning of combo box.
    ui->comboBox->setCurrentIndex(0);   // Set combo box to name.
    ui->nameLabel->setText(name);   // Set nameLabel to inputted name.
    ui->levelLabel->setText(level); // Set levelLabel to level.

    // Enable buttons in case they were disabled before.
    ui->startButton->setEnabled(true);
    ui->deleteButton->setEnabled(true);
    ui->restartButton->setEnabled(true);
}

void MainWindow::on_deleteButton_clicked()
{
    // Remove player info.
    Player::deletePlayer(ui->comboBox->currentIndex()); // Remove player from playerList.
    ui->comboBox->blockSignals(true);
    ui->comboBox->removeItem(ui->comboBox->currentIndex()); // Remove player from comboBox.

    // Set ui elements for selected player.
    if (ui->comboBox->count() > 0)
    {
        ui->nameLabel->setText(Player::playerName(ui->comboBox->currentIndex()));   // Set name to selected player.
        ui->levelLabel->setText(Player::playerLevel(ui->comboBox->currentIndex()));  // Set level to selected player.
    }
    else
    {
        ui->nameLabel->setText("");   // Delete name if last player.
        ui->levelLabel->setText("");  // Delete level if last player.
    }
}

void MainWindow::on_startButton_clicked()
{
    Player::makeMostRecent(ui->comboBox->currentIndex());   // Move selected player in pvz_players.csv to the top (most recent).

    // Set ui elements to selected player.
    ui->comboBox->blockSignals(true);
    ui->comboBox->removeItem(ui->comboBox->currentIndex()); // Remove selected item.
    ui->comboBox->insertItem(0, Player::playerName(0)); // Insert it back at the top.
    ui->comboBox->setCurrentIndex(0);   // Set combo box to top.
    ui->nameLabel->setText(Player::playerName(0));   // Set nameLabel to inputted name.
    ui->levelLabel->setText(Player::playerLevel(0)); // Set levelLabel to level (0 because new player).
}

void MainWindow::on_quitButton_clicked()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
