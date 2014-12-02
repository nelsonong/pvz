#include "level.h"
#include <QDebug>

std::vector<QStringList> levelList;
int Level::level = 0;
int Level::zombieType = 0;
int Level::sequencePosition = 0;

Level::Level()
{
}

void Level::loadLevels()
{
    QFile save_file(":/CSVs/pvz_levels.csv");
    if (save_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream text(&save_file);
        while(!text.atEnd())
        {
            levelList.push_back(text.readLine().split(":")); // Fill levelList with info from pvz_levels.csv.
        }
    }
}

bool Level::validLevelFile()
{
    QFile save_file(":/CSVs/pvz_levels.csv");
    if (!save_file.open(QIODevice::ReadOnly | QIODevice::Text))
        return 0;

    if (!levelList.size())
        return 0;

    return 1;
}

QStringList Level::sequence(int level)
{
    return levelList.at(level-1)[1].split(",");
}

int Level::rows(int level)
{
    if (level == 1)
    {
        return 2;
    }
    else if (level == 2)
    {
        return rand()%3 + 1;
    }
    else if (level > 2)
    {
        return rand()%5;
    }
    return -1;
}

QString Level::start(int level)
{
    return levelList.at(level-1)[3];
}

QString Level::interval(int level)
{
    return levelList.at(level-1)[4];
}

QString Level::decrement(int level)
{
    return levelList.at(level-1)[5];
}

int Level::sequenceSize(int level)
{
    QStringList temp = levelList.at(level-1)[1].split(",");
    return temp.size();
}
