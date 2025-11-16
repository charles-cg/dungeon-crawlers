#ifndef DUNGEON_H
#define DUNGEON_H

#include "Board.h"
#include "Graph.h"
#include "Monster.h"
#include "Hero.h"
#include "Room.h"
#include "Codex.h"

#include <fstream>
#include <sstream>
#include <iostream>

#define ROOMS_TXT "rooms.txt"

class Dungeon {
private:
    Hero* hero;

    Graph<Room<Monster>> board;

    Codex monsterCodex;

    Room<Monster>* roomArray;
    unsigned int totalRooms;

    bool loadRoomsTXT(std::string filename);

    int countLines(std::string filename);
public:
    Dungeon() : hero(nullptr), roomArray(nullptr), totalRooms(0) {
        monsterCodex.loadMonsterData();
    }
    ~Dungeon();
    bool loadRoomData();
};

#endif
