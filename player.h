#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
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
    static QString playerDate(int player);
    static QString playerName(int player);
    static int playerLevel(int player);
    static int playerListSize();
};

#endif // PLAYER_H
