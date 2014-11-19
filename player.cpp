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
    QStringList temp;
    temp.append(timestamp);
    temp.append(name);
    temp.append(level);
    playerList.push_back(temp);
}

QString Player::playerDate(int player)
{
    return playerList.at(player)[0];
}

QString Player::playerName(int player)
{
    return playerList.at(player)[1];
}

int Player::playerLevel(int player)
{
    return (playerList.at(player)[2]).toInt();
}

int Player::playerListSize()
{
    return playerList.size();
}
