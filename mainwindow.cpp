#include "mainwindow.h"
#include "ui_mainwindow.h"

Player playerObject;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), imageAdded(0)
{
    ui->setupUi(this);


    // Set button icons.
    ui->peaShooterButton->setIcon(QIcon(QPixmap(":/Images/Peashooter.png")));
    ui->sunFlowerButton->setIcon(QIcon(QPixmap(":/Images/Sunflower.png")));
    ui->cherryBombButton->setIcon(QIcon(QPixmap(":/Images/Cherrybomb.png")));
    ui->wallNutButton->setIcon(QIcon(QPixmap(":/Images/Wallnut.png")));
    ui->potatoMineButton->setIcon(QIcon(QPixmap(":/Images/Potatomine.png")));
    ui->snowPeaButton->setIcon(QIcon(QPixmap(":/Images/Snowpea.png")));
    ui->chomperButton->setIcon(QIcon(QPixmap(":/Images/Chomper.png")));
    ui->repeaterButton->setIcon(QIcon(QPixmap(":/Images/Repeater.png")));

    // Set icon sizes.
    ui->peaShooterButton->setIconSize(QSize(30,30));
    ui->sunFlowerButton->setIconSize(QSize(30,30));
    ui->cherryBombButton->setIconSize(QSize(30,30));
    ui->wallNutButton->setIconSize(QSize(30,30));
    ui->potatoMineButton->setIconSize(QSize(30,30));
    ui->snowPeaButton->setIconSize(QSize(30,30));
    ui->chomperButton->setIconSize(QSize(30,30));
    ui->repeaterButton->setIconSize(QSize(30,30));

    // Validate player file for unicode and alphanumerical.
    if (Player::validPlayerFile())  // If player file is valid, set settings for most recent player.
    {
        for (int i = 0; i < Player::playerListSize(); i++)
        {
          ui->comboBox->addItem(Player::playerName(i)); // Add existing players to comboBox.
        }

        // Set ui elements for most recent player.
        ui->nameLabel->setText(Player::playerName(0));      // Set name to most recent player.
        ui->levelLabel->setText(Player::playerLevel(0));    // Set level to most recent player.
        ui->comboBox->setCurrentIndex(0);                   // Set comboBox to most recent player.
    }
    else    // If invalid player file, clear file and only make new button available.
    {
        //Player::clearPlayerList();  // Discard current file.

        qDebug() << "invalid";
        // Set ui elements for if no players exist.
        ui->nameLabel->setText("");   // Delete player name.
        ui->levelLabel->setText("");  // Delete player level.

        // Disable buttons if no players.
        ui->startButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
        ui->restartButton->setEnabled(false);
    }

    ui->sunPointsLabel->setText("0");

    // Show PvZ logo until start is pressed.
    QPixmap *logo = new QPixmap(":/Images/Logo.png");
    scene = new QGraphicsScene(ui->graphicsView); // scene holds all objects in the scene.
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
    ui->nameLabel->setText(Player::playerName(index));      // Set name to selected player.
    ui->levelLabel->setText(Player::playerLevel(index));    // Set level to selected player.
}

void MainWindow::on_newButton_clicked()
{       
    // Add player info.
    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd");    // Get current date.
    QString name = QInputDialog::getText(this, "Get Name", "What's your name? ", QLineEdit::Normal, "");
    QString level = QString::number(1);         // Default: level 1.
    Player::addPlayer(timestamp, name, level);  // Add player to playerList.

    // Change ui elements.
    ui->comboBox->insertItem(0, name);  // Insert new name to beginning of combo box.
    ui->comboBox->setCurrentIndex(0);   // Set combo box to name.
    ui->nameLabel->setText(name);       // Set nameLabel to inputted name.
    ui->levelLabel->setText(level);     // Set levelLabel to level.

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
        ui->nameLabel->setText(Player::playerName(ui->comboBox->currentIndex()));       // Set name to selected player.
        ui->levelLabel->setText(Player::playerLevel(ui->comboBox->currentIndex()));     // Set level to selected player.
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
    ui->comboBox->insertItem(0, Player::playerName(0));     // Insert it back at the top.
    ui->comboBox->setCurrentIndex(0);                       // Set combo box to top.
    ui->nameLabel->setText(Player::playerName(0));          // Set nameLabel to inputted name.
    ui->levelLabel->setText(Player::playerLevel(0));        // Set levelLabel to level (0 because new player).

    // Enable buttons in case they were disabled before.
    ui->startButton->setEnabled(false);
    ui->newButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->restartButton->setEnabled(false);

    // Enable all plant buttons.
    ui->peaShooterButton->setEnabled(true);
    ui->sunFlowerButton->setEnabled(true);
    ui->cherryBombButton->setEnabled(true);
    ui->wallNutButton->setEnabled(true);
    ui->potatoMineButton->setEnabled(true);
    ui->snowPeaButton->setEnabled(true);
    ui->chomperButton->setEnabled(true);
    ui->repeaterButton->setEnabled(true);

    //QSound::play("C:/Users/Nelson/Downloads/Plants_vs._Zombies_(Main_Theme).wav");    // Play Plants vs. Zombies main theme.

    // Show frontyard image and send signal to start game.
    gameScreen = new GameScreen(ui->graphicsView);
    gameScreen->setFixedSize(ui->graphicsView->size());

    // Make scene and make dimensions same as graphicsView.
    scene = new QGraphicsScene(gameScreen);
    scene->setSceneRect(0, 0, gameScreen->width()-2, gameScreen->height()-2);

    // Add frontyard image to scene.
    QPixmap *frontyard = new QPixmap(":/Images/Frontyard.jpg");
    scene->addPixmap(frontyard->scaledToWidth(gameScreen->width()-4));

    connect(gameScreen,SIGNAL(click()),this,SLOT(addImage()));  // If gamescreen is clicked, add image.

    // Set scene and display.
    gameScreen->setScene(scene);
    gameScreen->show();

    // Move scene.
    moveTimer = new QTimer;
    connect(moveTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    moveTimer->start(50);

    // Create falling suns.
    createTimer = new QTimer;
    connect(createTimer, SIGNAL(timeout()), this, SLOT(createSun()));
    createTimer->start(10000);

    // Update sun points.
    updateSunPointsTimer = new QTimer;
    connect(updateSunPointsTimer, SIGNAL(timeout()), this, SLOT(updateSunPoints()));
    updateSunPointsTimer->start(10);

    for (int i = 0; i < 5; i++)
    {
        lawnMower = new LawnMower(GameScreen::grid[0][i]);
        scene->addItem(lawnMower);
    }
//    LawnMower *lawnMower2 = new LawnMower(QPoint(-20,135));
//    scene->addItem(lawnMower2);
//    LawnMower *lawnMower3 = new LawnMower(QPoint(-20,210));
//    scene->addItem(lawnMower3);
//    LawnMower *lawnMower4 = new LawnMower(QPoint(-20,290));
//    scene->addItem(lawnMower4);
//    LawnMower *lawnMower5 = new LawnMower(QPoint(-20,365));
//    scene->addItem(lawnMower5);
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
    plantClicked = "peashooter";
}

void MainWindow::on_sunFlowerButton_clicked()
{
    plantClicked = "sunflower";
}

void MainWindow::on_cherryBombButton_clicked()
{
    plantClicked = "cherrybomb";
}

void MainWindow::on_wallNutButton_clicked()
{
    plantClicked = "wallnut";
}

void MainWindow::on_potatoMineButton_clicked()
{
    plantClicked = "potatomine";
}

void MainWindow::on_snowPeaButton_clicked()
{
    plantClicked = "snowpea";
}

void MainWindow::on_chomperButton_clicked()
{
    plantClicked = "chomper";
}

void MainWindow::on_repeaterButton_clicked()
{
    plantClicked = "repeater";
}

void MainWindow::createSun()
{
    sun = new Sun;
    scene->addItem(sun);
}

void MainWindow::updateSunPoints()
{
    if (plantClicked == "peashooter" && imageAdded)
    {
        sun->sunPoints -= 100;
        plantClicked = "0";
        imageAdded = 0;
    }
    else if (plantClicked == "sunflower" && imageAdded)
    {
        sun->sunPoints -= 50;
        plantClicked = "0";
        imageAdded = 0;
    }
    else if (plantClicked == "cherrybomb" && imageAdded)
    {
        sun->sunPoints -= 150;
        plantClicked = "0";
        imageAdded = 0;
    }
    else if (plantClicked == "wallnut" && imageAdded)
    {
        sun->sunPoints -= 50;
        plantClicked = "0";
        imageAdded = 0;
    }
    else if (plantClicked == "potatomine" && imageAdded)
    {
        sun->sunPoints -= 25;
        plantClicked = "0";
        imageAdded = 0;
    }
    else if (plantClicked == "snowpea" && imageAdded)
    {
        sun->sunPoints -= 175;
        plantClicked = "0";
        imageAdded = 0;
    }
    else if (plantClicked == "chomper" && imageAdded)
    {
        sun->sunPoints -= 150;
        plantClicked = "0";
        imageAdded = 0;
    }
    else if (plantClicked == "repeater" && imageAdded)
    {
        sun->sunPoints -= 200;
        plantClicked = "0";
        imageAdded = 0;
    }

    ui->sunPointsLabel->setText(QString::number(sun->sunPoints));
}

void MainWindow::addImage()
{
    if ((plantClicked == "peashooter") && (!imageAdded) && (gameScreen->rectAvailable()) && (Sun::sunPoints >= 100))
    {
        peaShooter = new PeaShooter(gameScreen->currentGridPoint);
        scene->addItem(peaShooter);

        imageAdded++;
    }
    else if ((plantClicked == "sunflower") && (!imageAdded) && (gameScreen->rectAvailable()) && (Sun::sunPoints >= 50))
    {
        sunFlower = new SunFlower(gameScreen->currentGridPoint);
        scene->addItem(sunFlower);

        imageAdded++;
    }
    else if ((plantClicked == "cherrybomb") && (!imageAdded) && (gameScreen->rectAvailable()) && (Sun::sunPoints >= 150))
    {
        cherryBomb = new CherryBomb(gameScreen->currentGridPoint);
        scene->addItem(cherryBomb);

        imageAdded++;
    }
    else if ((plantClicked == "wallnut") && (!imageAdded) && (gameScreen->rectAvailable()) && (Sun::sunPoints >= 50))
    {
        wallNut = new WallNut(gameScreen->currentGridPoint);
        scene->addItem(wallNut);

        imageAdded++;
    }
    else if ((plantClicked == "potatomine") && (!imageAdded) && (gameScreen->rectAvailable()) && (Sun::sunPoints >= 25))
    {
        potatoMine = new PotatoMine(gameScreen->currentGridPoint);
        scene->addItem(potatoMine);

        imageAdded++;
    }
    else if ((plantClicked == "snowpea") && (!imageAdded) && (gameScreen->rectAvailable()) && (Sun::sunPoints >= 175))
    {
        snowPea = new SnowPea(gameScreen->currentGridPoint);
        scene->addItem(snowPea);

        imageAdded++;
    }
    else if ((plantClicked == "chomper") && (!imageAdded) && (gameScreen->rectAvailable()) && (Sun::sunPoints >= 150))
    {
        chomper = new Chomper(gameScreen->currentGridPoint);
        scene->addItem(chomper);

        imageAdded++;
    }
    else if ((plantClicked == "repeater") && (!imageAdded) && (gameScreen->peaShooterRect()) && (Sun::sunPoints >= 200))
    {
        repeater = new Repeater(gameScreen->currentGridPoint);
        scene->addItem(repeater);

        imageAdded++;
    }
}
