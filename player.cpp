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

void Player::clearPlayerList()
{
    playerList.clear();
    updatePlayersFile();
}

bool Player::validPlayerFile()
{
    if (playerList.empty())
        return 0;

    for (int player = 0; player < playerListSize(); player++)
    {
        for (int nameChar = 0; nameChar < playerName(player).size(); nameChar++)
        {
            if (!playerName(player).at(nameChar).isLetterOrNumber())
                return 0;
        }
    }

    for (int player = 0; player < playerListSize(); player++)
    {
        for (int levelChar = 0; levelChar < playerLevel(player).size(); levelChar++)
        {
            if (!playerLevel(player).at(levelChar).isDigit())
                return 0;
            else if (playerLevel(player).toInt() < 0 || playerLevel(player).toInt() > 100)
                return 0;
        }
    }

    return 1;
}

void Player::addPlayer(QString timestamp, QString name, QString level)
{
    QStringList player;
    player.append(timestamp);
    player.append(name);
    player.append(level);
    playerList.insert(playerList.begin(), player);
    updatePlayersFile();
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
