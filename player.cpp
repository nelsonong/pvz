#include "player.h"

std::vector<QStringList> playerList;

Player::Player()
{
}

void Player::loadPlayers()
{
    QFile save_file(":/CSVs/pvz_players.csv");
    if (save_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream text(&save_file);
        while(!text.atEnd())
        {
            playerList.push_back(text.readLine().split(":")); // Fill playerList with info from pvz_player.csv.
        }

        for (int i = 0; i < playerList.size()-1; i++)
        {
            int maxIndex = i;
            QStringList max = playerList.at(i);
            for (int j = i+1; j < playerList.size(); j++)
            {
                if (max[0].toInt() < playerList.at(j)[0].toInt())
                {
                    max = playerList.at(j);
                    maxIndex = j;
                }
            }
            std::swap(playerList[i],playerList[maxIndex]);
        }
        updatePlayersFile();
    }
    save_file.close();
}

void Player::clearPlayers()
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
            if (playerName(player).size() > 10)
                return 0;
        }
    }

    for (int player = 0; player < playerList.size(); player++)
    {
        for (int levelChar = 0; levelChar < playerLevel(player).size(); levelChar++)
        {
            if (!(playerLevel(player).at(levelChar)).isDigit())
                return 0;
            else if (playerLevel(player).toInt() <= 0 || playerLevel(player).toInt() > 100)
                return 0;
        }
    }

    return 1;
}

bool Player::validPlayerName(QString name)
{
    for (int i = 0; i < name.size(); i++)
    {
        if (!name[i].isLetterOrNumber())
            return 0;
        else if (name.size() > 10)
            return 0;
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

void Player::makePlayerMostRecent(int index, QString date)
{
    playerList.at(index)[0] = date;
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
    return (int)playerList.size();
}

void Player::updatePlayersFile()
{
    QFile save_file(":/CSVs/pvz_players.csv");  // Program can read from csv from resource file, but can't write.
                                                // Temporary solution is to use local file not in resources.
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

void Player::updateLevel(QString level)
{
    playerList.at(0)[2] = level;
    updatePlayersFile();
}
