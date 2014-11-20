#include "player.h"

Player::Player()
{
    fillPlayerList();
}

static std::vector<QStringList> playerList;

void Player::fillPlayerList()
{
    QFile save_file("C:/Qt/Tools/QtCreator/bin/PvZ/pvz_players.csv");
    if (save_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream text(&save_file);

        while(!text.atEnd())
        {
            playerList.push_back(text.readLine().split(":")); // Fill playerList with info from pvz_player.csv.
        }

        save_file.close();
    }
}

void Player::addPlayer(QString timestamp, QString name, QString level)
{
    QStringList player;
    player.append(timestamp);
    player.append(name);
    player.append(level);
    playerList.insert(playerList.begin(), player);

    QFile save_file("C:/Qt/Tools/QtCreator/bin/PvZ/pvz_players.csv");
    if (save_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream text(&save_file);

        // Save player info.
        text << timestamp << ":" << name << ":0\n"; // Add player info to pvz_players.csv.
        Player::addPlayer(timestamp, name, 0);  // Add player info to playerList.

        save_file.close();
    }
}

void Player::deletePlayer(int index)
{
    playerList.erase(playerList.begin() + index);
    updatePlayersFile();
}

void Player::makeMostRecent(int index)
{
    playerList.insert(playerList.begin(), playerList.at(index));
    playerList.erase(playerList.begin() + index + 1);
    updatePlayersFile();
}

QString Player::playerDate(int player)
{
    return playerList.at(player)[0];
}

QString Player::playerName(int player)
{
    return playerList.at(player)[1];
}

QString Player::playerLevel(int player)
{
    return playerList.at(player)[2];
}

int Player::playerListSize()
{
    return playerList.size();
}

void Player::updatePlayersFile()
{
    QFile save_file("C:/Qt/Tools/QtCreator/bin/PvZ/pvz_players.csv");
    if (save_file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        QTextStream text(&save_file);

        // Rewrite pvz_players.csv with player sent to bottom.
        for (int i = 0; i < playerListSize(); i++)
        {
            text << playerDate(i) << ":" << playerName(i) << ":" << playerLevel(i) << "\n";
        }

        save_file.close();
    }
}
