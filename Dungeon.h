#ifndef DUNGEON_H
#define DUNGEON_H

#include "Graph.h"
#include "Monster.h"
#include "Hero.h"
#include "Room.h"
#include "Codex.h"

#include <fstream>
#include <sstream>
#include <iostream>

#define ROOMS_TXT "rooms.txt"
#define PATHS_TXT "paths.txt"

#define ADD_PATH_NUMBER_ARGUMENTS 4

class Dungeon {
private:
    Hero* hero;

    Graph<Room<Monster>> board;

    Codex monsterCodex;

    unsigned int totalRooms;

    bool loadRoomsTXT(std::string filename);

    int countLines(std::string filename);

    unsigned int totalPaths;

    bool addRoomPath(std::string& roomFromId, std::string& roomToId, int weight = 1, bool directed = false);

    bool loadPathsTXT(std::string filename);
public:
    Dungeon() : totalRooms(0) {
        monsterCodex.loadMonsterData();
    }

    ~Dungeon();

    bool loadRoomData();

    bool loadPathData();

    void printBoard() const;

    void setStartingRoom();

    void showNeghboringRooms() const;

    bool moveHero(const std::string& roomId);

    Monster* getCurrentMonster();

    bool shouldTriggerEncounter();

    bool handleEncounter();

    Hero* getHero();

    void setCurrentRoomMonsterDefeated();

    void setHero(const std::string& name);
};

#endif
