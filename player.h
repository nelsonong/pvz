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
    //void fillPlayerList();                  // Fill playerList with text file data.
    static void orderPlayerList();          // Order text file from most to least recent and fill playerList.
    static void clearPlayerList();          // Clears text file.
    static bool validPlayerFile();          // Checks whether text file is valid or not.
    static void addPlayer(QString timestamp, QString name, QString level);  // Add player to playerList and text file.
    static void deletePlayer(int index);    // Delete player from playerList and text file.
    static void makeMostRecent(int index);  // Make specified player the most recent player.
    static QString playerDate(int player);  // Returns timestamp, given player.
    static QString playerName(int player);  // Returns name, given player.
    static QString playerLevel(int player); // Returns level, given player.
    static int playerListSize();            // Returns amount of players in playerList/text file.
    static void updatePlayersFile();        // Updates text file with players from playerList.
};

#endif // PLAYER_H
