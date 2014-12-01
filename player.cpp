#include "player.h"
#include <QDebug>

Player::Player()
{
    orderPlayerList();
    //fillPlayerList();
}

static std::vector<QStringList> playerList;

void Player::fillPlayerList()
{
    QFile save_file(":/CSVs/pvz_players.csv");
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

void Player::orderPlayerList()
{
    QFile save_file(":/CSVs/pvz_players.csv");
    if (save_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream text(&save_file);

        while(!text.atEnd())
        {
            playerList.push_back(text.readLine().split(":")); // Fill playerList with info from pvz_player.csv.
        }

        if (playerList.size() > 0)
        {
            for (int i = 0; i < playerList.size()-1; i++)
            {
                QStringList max = playerList.at(i);
                int maxIndex;
                for (int j = i+1; j < playerList.size(); j++)
                {
                    if (max[0].toInt() < playerList.at(j)[0].toInt())
                    {
                        max = playerList.at(j);
                        maxIndex = j;
                    }
                }

                QStringList temp = playerList.at(i);
                playerList.at(i) = playerList.at(maxIndex);
                playerList.at(maxIndex) = temp;
            }
            for(int i=0;i<playerList.size();i++)
            {
                qDebug()<<playerList.at(i)[0];
            }
            updatePlayersFile();

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

    qDebug() << "not empty";
    for (int player = 0; player < playerList.size(); player++)
    {
        for (int nameChar = 0; nameChar < playerName(player).size(); nameChar++)
        {
            if (!playerName(player).at(nameChar).isLetterOrNumber())
                return 0;
        }
    }

    for (int player = 0; player < playerList.size(); player++)
    {
        for (int levelChar = 0; levelChar < playerLevel(player).size(); levelChar++)
        {
            if (!(playerLevel(player).at(levelChar)).isDigit())
                return 0;
            else if (playerLevel(player).toInt() < 0 || playerLevel(player).toInt() > 100)
                return 0;
        }
    }

    return 1;
}

void Player::addPlayer(QString timestamp, QString name, QString level)
{
    QStringList temp_player;
    temp_player.append(timestamp);
    temp_player.append(name);
    temp_player.append(level);
    playerList.insert(playerList.begin(), temp_player);
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
    return (int)playerList.size();
}

void Player::updatePlayersFile()
{
    QFile save_file(":/CSVs/pvz_players.csv");
    if (save_file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append | QIODevice::Truncate))
    {
        QTextStream text(&save_file);

        // Rewrite pvz_players.csv.
        for (int i = 0; i < playerList.size(); i++)
        {
            text << playerDate(i) << ":" << playerName(i) << ":" << playerLevel(i) << "\n";
        }

        save_file.close();
    }
}
