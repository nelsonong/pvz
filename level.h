#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QString>

class Level
{
public:
    Level();
    static void loadLevels();                   // Load level file into easily accessible vector.
    static bool validLevelFile();               // Checks whether text file is valid or not.
    static int level;                           // Holds user's level.
    static int zombieType;                      // Holds zombie type (changes depending on position in sequence).
    static int sequencePosition;                // Holds sequence position.
    static QStringList sequence(int level);     // Returns zombie sequence, given level.
    static int rows(int level);                 // Returns rows, given level.
    static QString start(int level);            // Returns start, given level.
    static QString interval(int level);         // Returns start, given level.
    static QString decrement(int level);        // Returns amount of levels in text file.
    static int sequenceSize(int level);         // Returns amount of levels in text file.
};

#endif // LEVEL_H
