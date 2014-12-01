#include "mainwindow.h"
#include "ui_mainwindow.h"

Player playerlist;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), imageAdded(0)
{
    ui->setupUi(this);

    qDebug() << "1";
    // Load players from text file in order of most to least recent.
    Player::loadPlayers();

    qDebug() << "2";
    // Validate player file (unicode/alphanumerical).
    if (Player::validPlayerFile())
    {
        // If playerFile is valid, load most recent players into comboBox and labels.
        for (int i = 0; i < Player::playerListSize(); i++)
        {
          ui->comboBox->addItem(Player::playerName(i));
        }

        // Set ui elements for most recent player.
        ui->nameLabel->setText(Player::playerName(0));
        ui->levelLabel->setText(Player::playerLevel(0));
        ui->comboBox->setCurrentIndex(0);
    }
    else
    {
        // If file is invalid, discard current file.
        Player::clearPlayers();

        // Set blank ui elements.
        ui->nameLabel->setText("");
        ui->levelLabel->setText("");

        // Only enable new button.
        ui->startButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
        ui->restartButton->setEnabled(false);
        ui->quitButton->setEnabled(false);
    }


    ui->sunPointsLabel->setText("0");

    // Show PvZ logo until start is pressed.
    QPixmap *logo = new QPixmap(":/Images/Logo.png");
    scene = new QGraphicsScene(ui->graphicsView); // scene holds all objects in the scene.
    scene->addPixmap(logo->scaledToWidth(ui->graphicsView->width()/1.5));
    ui->graphicsView->setScene(scene);

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
    ui->repeaterButton->setIconSize(QSize(35,30));

    // Set toop-tip messages.
    ui->peaShooterButton->setToolTip("Pea Shooter, Cost: 100");
    ui->sunFlowerButton->setToolTip("Sun Flower, Cost: 50");
    ui->cherryBombButton->setToolTip("Cherry Bomb, Cost: 150");
    ui->wallNutButton->setToolTip("Wall Nut, Cost: 50");
    ui->potatoMineButton->setToolTip("Potato Mine, Cost: 25");
    ui->snowPeaButton->setToolTip("Snow Pea, Cost: 175");
    ui->chomperButton->setToolTip("Chomper, Cost: 150");
    ui->repeaterButton->setToolTip("Repeater, Cost: 200");

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
    Player::makePlayerMostRecent(ui->comboBox->currentIndex());   // Move selected player in pvz_players.csv to the top (most recent).

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
    advanceTimer = new QTimer;
    connect(advanceTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    advanceTimer->start(50);

    // Create falling suns.
    createSunTimer = new QTimer;
    connect(createSunTimer, SIGNAL(timeout()), this, SLOT(createSun()));
    createSunTimer->start(10000);

    // Update sun points.
    updateTimer = new QTimer;
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateSunPoints()));
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateButtons()));
    updateTimer->start(20);

    for (int i = 0; i < 5; i++)
    {
        lawnMower = new LawnMower(gameScreen->grid[0][i]);
        scene->addItem(lawnMower);
    }

    for (int i = 0; i < 3; i++)
    {
        regular = new Regular(gameScreen->grid[9][rand()%5]);
        scene->addItem(regular);
    }

    // Timers to monitor cooldowns of plant buttons.
    peaShooterCooldownTimer = new QTimer;
    sunFlowerCooldownTimer = new QTimer;
    cherryBombCooldownTimer = new QTimer;
    wallNutCooldownTimer = new QTimer;
    potatoMineCooldownTimer = new QTimer;
    snowPeaCooldownTimer = new QTimer;
    chomperCooldownTimer = new QTimer;
    repeaterCooldownTimer = new QTimer;
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

    // Make all buttons except pea shooter flat.
    ui->peaShooterButton->setFlat(false);
    ui->sunFlowerButton->setFlat(true);
    ui->cherryBombButton->setFlat(true);
    ui->wallNutButton->setFlat(true);
    ui->potatoMineButton->setFlat(true);
    ui->snowPeaButton->setFlat(true);
    ui->chomperButton->setFlat(true);
    ui->repeaterButton->setFlat(true);
}

void MainWindow::on_sunFlowerButton_clicked()
{
    plantClicked = "sunflower";

    // Make all buttons except sunflower flat.
    ui->sunFlowerButton->setFlat(false);
    ui->peaShooterButton->setFlat(true);
    ui->cherryBombButton->setFlat(true);
    ui->wallNutButton->setFlat(true);
    ui->potatoMineButton->setFlat(true);
    ui->snowPeaButton->setFlat(true);
    ui->chomperButton->setFlat(true);
    ui->repeaterButton->setFlat(true);
}

void MainWindow::on_cherryBombButton_clicked()
{
    plantClicked = "cherrybomb";

    // Make all buttons except cherry bomb flat.
    ui->cherryBombButton->setFlat(false);
    ui->peaShooterButton->setFlat(true);
    ui->sunFlowerButton->setFlat(true);
    ui->wallNutButton->setFlat(true);
    ui->potatoMineButton->setFlat(true);
    ui->snowPeaButton->setFlat(true);
    ui->chomperButton->setFlat(true);
    ui->repeaterButton->setFlat(true);
}

void MainWindow::on_wallNutButton_clicked()
{
    plantClicked = "wallnut";

    // Make all buttons except wall nut flat.
    ui->wallNutButton->setFlat(false);
    ui->peaShooterButton->setFlat(true);
    ui->sunFlowerButton->setFlat(true);
    ui->cherryBombButton->setFlat(true);
    ui->potatoMineButton->setFlat(true);
    ui->snowPeaButton->setFlat(true);
    ui->chomperButton->setFlat(true);
    ui->repeaterButton->setFlat(true);
}

void MainWindow::on_potatoMineButton_clicked()
{
    plantClicked = "potatomine";

    // Make all buttons except potato mine flat.
    ui->potatoMineButton->setFlat(false);
    ui->peaShooterButton->setFlat(true);
    ui->sunFlowerButton->setFlat(true);
    ui->cherryBombButton->setFlat(true);
    ui->wallNutButton->setFlat(true);
    ui->snowPeaButton->setFlat(true);
    ui->chomperButton->setFlat(true);
    ui->repeaterButton->setFlat(true);
}

void MainWindow::on_snowPeaButton_clicked()
{
    plantClicked = "snowpea";

    // Make all buttons except snow pea flat.
    ui->snowPeaButton->setFlat(false);
    ui->peaShooterButton->setFlat(true);
    ui->sunFlowerButton->setFlat(true);
    ui->cherryBombButton->setFlat(true);
    ui->wallNutButton->setFlat(true);
    ui->potatoMineButton->setFlat(true);
    ui->chomperButton->setFlat(true);
    ui->repeaterButton->setFlat(true);
}

void MainWindow::on_chomperButton_clicked()
{
    plantClicked = "chomper";

    // Make all buttons except chomper flat.
    ui->chomperButton->setFlat(false);
    ui->peaShooterButton->setFlat(true);
    ui->sunFlowerButton->setFlat(true);
    ui->cherryBombButton->setFlat(true);
    ui->wallNutButton->setFlat(true);
    ui->potatoMineButton->setFlat(true);
    ui->snowPeaButton->setFlat(true);
    ui->repeaterButton->setFlat(true);
}

void MainWindow::on_repeaterButton_clicked()
{
    plantClicked = "repeater";

    // Make all buttons except repeater flat.
    ui->repeaterButton->setFlat(false);
    ui->peaShooterButton->setFlat(true);
    ui->sunFlowerButton->setFlat(true);
    ui->cherryBombButton->setFlat(true);
    ui->wallNutButton->setFlat(true);
    ui->potatoMineButton->setFlat(true);
    ui->snowPeaButton->setFlat(true);
    ui->chomperButton->setFlat(true);
}

void MainWindow::createSun()
{
    sun = new Sun;
    scene->addItem(sun);
}

void MainWindow::updateSunPoints()
{
    // If plant has been added to the scene, start cooldown timer and decrement sun points.
    if (plantClicked == "peashooter" && imageAdded)
    {
        sun->sunPoints -= 100;
        plantClicked = "0";
        imageAdded = 0;

        peaShooterCooldownTimer->start(peaShooter->seeding*1000);
        connect(peaShooterCooldownTimer, SIGNAL(timeout()), peaShooterCooldownTimer, SLOT(stop()));
    }
    else if (plantClicked == "sunflower" && imageAdded)
    {
        sun->sunPoints -= 50;
        plantClicked = "0";
        imageAdded = 0;

        sunFlowerCooldownTimer->start(sunFlower->seeding*1000);
        connect(sunFlowerCooldownTimer, SIGNAL(timeout()), sunFlowerCooldownTimer, SLOT(stop()));
    }
    else if (plantClicked == "cherrybomb" && imageAdded)
    {
        sun->sunPoints -= 150;
        plantClicked = "0";
        imageAdded = 0;

        cherryBombCooldownTimer->start(cherryBomb->seeding*1000);
        connect(cherryBombCooldownTimer, SIGNAL(timeout()), cherryBombCooldownTimer, SLOT(stop()));
    }
    else if (plantClicked == "wallnut" && imageAdded)
    {
        sun->sunPoints -= 50;
        plantClicked = "0";
        imageAdded = 0;

        wallNutCooldownTimer->start(wallNut->seeding*1000);
        connect(wallNutCooldownTimer, SIGNAL(timeout()), wallNutCooldownTimer, SLOT(stop()));
    }
    else if (plantClicked == "potatomine" && imageAdded)
    {
        sun->sunPoints -= 25;
        plantClicked = "0";
        imageAdded = 0;

        potatoMineCooldownTimer->start(potatoMine->seeding*1000);
        connect(potatoMineCooldownTimer, SIGNAL(timeout()), potatoMineCooldownTimer, SLOT(stop()));
    }
    else if (plantClicked == "snowpea" && imageAdded)
    {
        sun->sunPoints -= 175;
        plantClicked = "0";
        imageAdded = 0;

        snowPeaCooldownTimer->start(snowPea->seeding*1000);
        connect(snowPeaCooldownTimer, SIGNAL(timeout()), snowPeaCooldownTimer, SLOT(stop()));
    }
    else if (plantClicked == "chomper" && imageAdded)
    {
        sun->sunPoints -= 150;
        plantClicked = "0";
        imageAdded = 0;

        chomperCooldownTimer->start(chomper->seeding*1000);
        connect(chomperCooldownTimer, SIGNAL(timeout()), chomperCooldownTimer, SLOT(stop()));
    }
    else if (plantClicked == "repeater" && imageAdded)
    {
        sun->sunPoints -= 200;
        plantClicked = "0";
        imageAdded = 0;

        repeaterCooldownTimer->start(repeater->seeding*1000);
        connect(repeaterCooldownTimer, SIGNAL(timeout()), repeaterCooldownTimer, SLOT(stop()));
    }

    ui->sunPointsLabel->setText(QString::number(sun->sunPoints));
}

void MainWindow::updateButtons()
{
    // If there aren't enough sun points or if plants are on cooldown, disable buttons.
    if (Sun::sunPoints < 100 || peaShooterCooldownTimer->isActive())
        ui->peaShooterButton->setEnabled(false);
    else
        ui->peaShooterButton->setEnabled(true);

    if (Sun::sunPoints < 50 || sunFlowerCooldownTimer->isActive())
        ui->sunFlowerButton->setEnabled(false);
    else
        ui->sunFlowerButton->setEnabled(true);

    if (Sun::sunPoints < 150 || cherryBombCooldownTimer->isActive())
        ui->cherryBombButton->setEnabled(false);
    else
        ui->cherryBombButton->setEnabled(true);

    if (Sun::sunPoints < 50 || wallNutCooldownTimer->isActive())
        ui->wallNutButton->setEnabled(false);
    else
        ui->wallNutButton->setEnabled(true);

    if (Sun::sunPoints < 25 || potatoMineCooldownTimer->isActive())
        ui->potatoMineButton->setEnabled(false);
    else
        ui->potatoMineButton->setEnabled(true);

    if (Sun::sunPoints < 175 || snowPeaCooldownTimer->isActive())
        ui->snowPeaButton->setEnabled(false);
    else
        ui->snowPeaButton->setEnabled(true);

    if (Sun::sunPoints < 150 || chomperCooldownTimer->isActive())
        ui->chomperButton->setEnabled(false);
    else
        ui->chomperButton->setEnabled(true);

    if (Sun::sunPoints < 200 || repeaterCooldownTimer->isActive())
        ui->repeaterButton->setEnabled(false);
    else
        ui->repeaterButton->setEnabled(true);

    // While cooldown of buttons are running, set button text to remaining time.
    if (peaShooterCooldownTimer->isActive())
        ui->peaShooterButton->setText(QString::number(peaShooterCooldownTimer->remainingTime()/1000));
    else
        ui->peaShooterButton->setText("");

    if (sunFlowerCooldownTimer->isActive())
        ui->sunFlowerButton->setText(QString::number(sunFlowerCooldownTimer->remainingTime()/1000));
    else
        ui->sunFlowerButton->setText("");

    if (cherryBombCooldownTimer->isActive())
        ui->cherryBombButton->setText(QString::number(cherryBombCooldownTimer->remainingTime()/1000));
    else
        ui->cherryBombButton->setText("");

    if (wallNutCooldownTimer->isActive())
        ui->wallNutButton->setText(QString::number(wallNutCooldownTimer->remainingTime()/1000));
    else
        ui->wallNutButton->setText("");

    if (potatoMineCooldownTimer->isActive())
        ui->potatoMineButton->setText(QString::number(potatoMineCooldownTimer->remainingTime()/1000));
    else
        ui->potatoMineButton->setText("");

    if (snowPeaCooldownTimer->isActive())
        ui->snowPeaButton->setText(QString::number(snowPeaCooldownTimer->remainingTime()/1000));
    else
        ui->snowPeaButton->setText("");

    if (chomperCooldownTimer->isActive())
        ui->chomperButton->setText(QString::number(chomperCooldownTimer->remainingTime()/1000));
    else
        ui->chomperButton->setText("");

    if (repeaterCooldownTimer->isActive())
        ui->repeaterButton->setText(QString::number(repeaterCooldownTimer->remainingTime()/1000));
    else
        ui->repeaterButton->setText("");
}

void MainWindow::addImage()
{
    if ((plantClicked == "peashooter") && (!imageAdded) && (gameScreen->rectAvailable()))
    {
        peaShooter = new PeaShooter(gameScreen->currentGridPoint);
        scene->addItem(peaShooter);

        imageAdded++;
    }
    else if ((plantClicked == "sunflower") && (!imageAdded) && (gameScreen->rectAvailable()))
    {
        sunFlower = new SunFlower(gameScreen->currentGridPoint);
        scene->addItem(sunFlower);

        imageAdded++;
    }
    else if ((plantClicked == "cherrybomb") && (!imageAdded) && (gameScreen->rectAvailable()))
    {
        cherryBomb = new CherryBomb(gameScreen->currentGridPoint);
        scene->addItem(cherryBomb);

        imageAdded++;
    }
    else if ((plantClicked == "wallnut") && (!imageAdded) && (gameScreen->rectAvailable()))
    {
        wallNut = new WallNut(gameScreen->currentGridPoint);
        scene->addItem(wallNut);

        imageAdded++;
    }
    else if ((plantClicked == "potatomine") && (!imageAdded) && (gameScreen->rectAvailable()))
    {
        potatoMine = new PotatoMine(gameScreen->currentGridPoint);
        scene->addItem(potatoMine);

        imageAdded++;
    }
    else if ((plantClicked == "snowpea") && (!imageAdded) && (gameScreen->rectAvailable()))
    {
        snowPea = new SnowPea(gameScreen->currentGridPoint);
        scene->addItem(snowPea);

        imageAdded++;
    }
    else if ((plantClicked == "chomper") && (!imageAdded) && (gameScreen->rectAvailable()))
    {
        chomper = new Chomper(gameScreen->currentGridPoint);
        scene->addItem(chomper);

        imageAdded++;
    }
    else if ((plantClicked == "repeater") && (!imageAdded) && (gameScreen->peaShooterRect()))
    {
        repeater = new Repeater(gameScreen->currentGridPoint);
        scene->addItem(repeater);

        imageAdded++;
    }

    ui->peaShooterButton->setFlat(true);
    ui->sunFlowerButton->setFlat(true);
    ui->cherryBombButton->setFlat(true);
    ui->wallNutButton->setFlat(true);
    ui->potatoMineButton->setFlat(true);
    ui->snowPeaButton->setFlat(true);
    ui->chomperButton->setFlat(true);
    ui->repeaterButton->setFlat(true);
}
