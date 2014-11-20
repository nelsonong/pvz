#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QString>

class Player
{
public:
    Player();
    void fillPlayerList();
    static void addPlayer(QString timestamp, QString name, QString level);
    static void deletePlayer(int index);
    static void makeMostRecent(int index);
    static QString playerDate(int player);
    static QString playerName(int player);
    static QString playerLevel(int player);
    static int playerListSize();
    static void updatePlayersFile();
};

#endif // PLAYER_H
