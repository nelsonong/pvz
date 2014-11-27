#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <QDebug>

Player playerObject;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (Player::validPlayerFile())  // If player file is valid, set settings for most recent player.
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
    else    // If invalid player file, clear file and only make new button available.
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

    // Show PvZ logo until start is pressed.
    QPixmap *logo = new QPixmap(":/Images/Logo.png");
    scene = new QGraphicsScene(this); // scene holds all objects in the scene.
    scene->addPixmap(logo->scaledToWidth(ui->graphicsView->width()/1.5));
    ui->graphicsView->setScene(scene);

    // Disable all plant buttons.
    ui->peaShooterButton->setEnabled(false);
    ui->sunFlowerButton->setEnabled(false);
    ui->cherryBombButton->setEnabled(false);
    ui->wallNutButton->setEnabled(false);
    ui->potatoMineButton->setEnabled(false);
    ui->snowPeaButton->setEnabled(false);
    ui->chomperButton->setEnabled(false);
    ui->repeaterButton->setEnabled(false);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    // Set ui elements for selected player.
    ui->nameLabel->setText(Player::playerName(index));   // Set name to selected player.
    ui->levelLabel->setText(Player::playerLevel(index));  // Set level to selected player.
}

void MainWindow::addImage11()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(60,95);
    disconnect(gameScreen,SIGNAL(click11()),this,SLOT(addImage11()));
}

void MainWindow::addImage12()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(60,175);
    disconnect(gameScreen,SIGNAL(click12()),this,SLOT(addImage12()));
}

void MainWindow::addImage13()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(60,250);
    disconnect(gameScreen,SIGNAL(click13()),this,SLOT(addImage13()));
}

void MainWindow::addImage14()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(60,325);
    disconnect(gameScreen,SIGNAL(click14()),this,SLOT(addImage14()));
}

void MainWindow::addImage15()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(60,405);
    disconnect(gameScreen,SIGNAL(click15()),this,SLOT(addImage15()));
}

void MainWindow::addImage21()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(127,95);
    disconnect(gameScreen,SIGNAL(click21()),this,SLOT(addImage21()));
}

void MainWindow::addImage22()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(127,175);
    disconnect(gameScreen,SIGNAL(click22()),this,SLOT(addImage22()));
}

void MainWindow::addImage23()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(125,250);
    disconnect(gameScreen,SIGNAL(click23()),this,SLOT(addImage23()));
}

void MainWindow::addImage24()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(125,325);
    disconnect(gameScreen,SIGNAL(click24()),this,SLOT(addImage24()));
}

void MainWindow::addImage25()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(125,405);
    disconnect(gameScreen,SIGNAL(click25()),this,SLOT(addImage25()));
}

void MainWindow::addImage31()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(185,95);
    disconnect(gameScreen,SIGNAL(click31()),this,SLOT(addImage31()));
}

void MainWindow::addImage32()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(185,175);
    disconnect(gameScreen,SIGNAL(click32()),this,SLOT(addImage32()));
}

void MainWindow::addImage33()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(185,250);
    disconnect(gameScreen,SIGNAL(click33()),this,SLOT(addImage33()));
}

void MainWindow::addImage34()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(185,325);
    disconnect(gameScreen,SIGNAL(click34()),this,SLOT(addImage34()));
}

void MainWindow::addImage35()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(185,405);
    disconnect(gameScreen,SIGNAL(click35()),this,SLOT(addImage35()));
}

void MainWindow::addImage41()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,95);
    disconnect(gameScreen,SIGNAL(click41()),this,SLOT(addImage41()));
}

void MainWindow::addImage42()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,175);
    disconnect(gameScreen,SIGNAL(click42()),this,SLOT(addImage42()));
}

void MainWindow::addImage43()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,250);
    disconnect(gameScreen,SIGNAL(click43()),this,SLOT(addImage43()));
}

void MainWindow::addImage44()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,325);
    disconnect(gameScreen,SIGNAL(click44()),this,SLOT(addImage44()));
}

void MainWindow::addImage45()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage51()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage52()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage53()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage54()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage55()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage61()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage62()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage63()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage64()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage65()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage71()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage72()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage73()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage74()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage75()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage81()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage82()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage83()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage84()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage85()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage91()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage92()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage93()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage94()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
}

void MainWindow::addImage95()
{
    QGraphicsPixmapItem *pm = scene->addPixmap(plant->scaledToWidth(50));
    pm->setOffset(-25,-25);
    pm->setPos(247,405);
    disconnect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
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

    // Enable buttons in case they were disabled before.
    ui->startButton->setEnabled(false);
    ui->newButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->restartButton->setEnabled(false);

    QSound::play("C:/Users/Nelson/Downloads/Plants_vs._Zombies_(Main_Theme).wav");    // Play Plants vs. Zombies main theme.

    // Show frontyard image and send signal to start game.
    gameScreen = new GameScreen(ui->graphicsView);
    gameScreen->setFixedSize(ui->graphicsView->size());

    // Make scene and make dimensions same as graphicsView.
    scene = new QGraphicsScene(gameScreen);
    scene->setSceneRect(0, 0, gameScreen->width()-2, gameScreen->height()-2);

    // Add frontyard image to scene.
    QPixmap *frontyard = new QPixmap(":/Images/Frontyard.jpg");
    scene->addPixmap(frontyard->scaledToWidth(gameScreen->width()-4));

    connect(gameScreen,SIGNAL(click11()),this,SLOT(addImage11()));
    connect(gameScreen,SIGNAL(click12()),this,SLOT(addImage12()));
    connect(gameScreen,SIGNAL(click13()),this,SLOT(addImage13()));
    connect(gameScreen,SIGNAL(click14()),this,SLOT(addImage14()));
    connect(gameScreen,SIGNAL(click15()),this,SLOT(addImage15()));
    connect(gameScreen,SIGNAL(click21()),this,SLOT(addImage21()));
    connect(gameScreen,SIGNAL(click22()),this,SLOT(addImage22()));
    connect(gameScreen,SIGNAL(click23()),this,SLOT(addImage23()));
    connect(gameScreen,SIGNAL(click24()),this,SLOT(addImage24()));
    connect(gameScreen,SIGNAL(click25()),this,SLOT(addImage25()));
    connect(gameScreen,SIGNAL(click31()),this,SLOT(addImage31()));
    connect(gameScreen,SIGNAL(click32()),this,SLOT(addImage32()));
    connect(gameScreen,SIGNAL(click33()),this,SLOT(addImage33()));
    connect(gameScreen,SIGNAL(click34()),this,SLOT(addImage34()));
    connect(gameScreen,SIGNAL(click35()),this,SLOT(addImage35()));
    connect(gameScreen,SIGNAL(click41()),this,SLOT(addImage41()));
    connect(gameScreen,SIGNAL(click42()),this,SLOT(addImage42()));
    connect(gameScreen,SIGNAL(click43()),this,SLOT(addImage43()));
    connect(gameScreen,SIGNAL(click44()),this,SLOT(addImage44()));
    connect(gameScreen,SIGNAL(click45()),this,SLOT(addImage45()));
    connect(gameScreen,SIGNAL(click51()),this,SLOT(addImage51()));
    connect(gameScreen,SIGNAL(click52()),this,SLOT(addImage52()));
    connect(gameScreen,SIGNAL(click53()),this,SLOT(addImage53()));
    connect(gameScreen,SIGNAL(click54()),this,SLOT(addImage54()));
    connect(gameScreen,SIGNAL(click65()),this,SLOT(addImage55()));
    connect(gameScreen,SIGNAL(click61()),this,SLOT(addImage61()));
    connect(gameScreen,SIGNAL(click62()),this,SLOT(addImage62()));
    connect(gameScreen,SIGNAL(click63()),this,SLOT(addImage63()));
    connect(gameScreen,SIGNAL(click64()),this,SLOT(addImage64()));
    connect(gameScreen,SIGNAL(click65()),this,SLOT(addImage65()));
    connect(gameScreen,SIGNAL(click71()),this,SLOT(addImage71()));
    connect(gameScreen,SIGNAL(click72()),this,SLOT(addImage72()));
    connect(gameScreen,SIGNAL(click73()),this,SLOT(addImage73()));
    connect(gameScreen,SIGNAL(click74()),this,SLOT(addImage74()));
    connect(gameScreen,SIGNAL(click75()),this,SLOT(addImage75()));
    connect(gameScreen,SIGNAL(click81()),this,SLOT(addImage81()));
    connect(gameScreen,SIGNAL(click82()),this,SLOT(addImage82()));
    connect(gameScreen,SIGNAL(click83()),this,SLOT(addImage83()));
    connect(gameScreen,SIGNAL(click84()),this,SLOT(addImage84()));
    connect(gameScreen,SIGNAL(click85()),this,SLOT(addImage85()));
    connect(gameScreen,SIGNAL(click91()),this,SLOT(addImage91()));
    connect(gameScreen,SIGNAL(click92()),this,SLOT(addImage92()));
    connect(gameScreen,SIGNAL(click93()),this,SLOT(addImage93()));
    connect(gameScreen,SIGNAL(click94()),this,SLOT(addImage94()));
    connect(gameScreen,SIGNAL(click95()),this,SLOT(addImage95()));

    // Set scene and display.
    gameScreen->setScene(scene);
    gameScreen->show();

    moveTimer = new QTimer;
    connect(moveTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    moveTimer->start(60);

    createTimer = new QTimer;
    connect(createTimer, SIGNAL(timeout()), this, SLOT(createSun()));
    createTimer->start(10000);

    destroyTimer = new QTimer;
    connect(destroyTimer, SIGNAL(timeout()), this, SLOT(destroySun()));

    //createSun();

    // Enable all plant buttons.
    ui->peaShooterButton->setEnabled(true);
    ui->sunFlowerButton->setEnabled(true);
    ui->cherryBombButton->setEnabled(true);
    ui->wallNutButton->setEnabled(true);
    ui->potatoMineButton->setEnabled(true);
    ui->snowPeaButton->setEnabled(true);
    ui->chomperButton->setEnabled(true);
    ui->repeaterButton->setEnabled(true);
}

void MainWindow::on_quitButton_clicked()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_peaShooterButton_clicked()
{
    gameScreen->buttonPressed = 1;
    plant = new QPixmap(":/Images/Peashooter.png");
}

void MainWindow::on_sunFlowerButton_clicked()
{
    gameScreen->buttonPressed = 1;
    plant = new QPixmap(":/Images/Sunflower.png");
}

void MainWindow::on_cherryBombButton_clicked()
{
    gameScreen->buttonPressed = 1;
    plant = new QPixmap(":/Images/Cherrybomb.png");
}

void MainWindow::on_wallNutButton_clicked()
{
    gameScreen->buttonPressed = 1;
    plant = new QPixmap(":/Images/Wallnut.png");
}

void MainWindow::on_potatoMineButton_clicked()
{
    gameScreen->buttonPressed = 1;
    plant = new QPixmap(":/Images/Potatomine.png");
}

void MainWindow::on_snowPeaButton_clicked()
{
    gameScreen->buttonPressed = 1;
    plant = new QPixmap(":/Images/Snowpea.png");
}

void MainWindow::on_chomperButton_clicked()
{
    gameScreen->buttonPressed = 1;
    plant = new QPixmap(":/Images/Chomper.png");
}

void MainWindow::on_repeaterButton_clicked()
{
    gameScreen->buttonPressed = 1;
    plant = new QPixmap(":/Images/Repeater.png");
}

void MainWindow::createSun()
{
    sun = new Sun;
    scene->addItem(sun);
    destroyTimer->start(7500);
}

void MainWindow::destroySun()
{
    destroyTimer->stop();
    if (sun->sunClicked == false)
        delete sun;
    sun->sunClicked = false;
}
