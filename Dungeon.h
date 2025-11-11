#ifndef DUNGEON_H
#define DUNGEON_H

#include "Board.h"
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

    Board<Room<Monster>> board;

    Codex monsterCodex;

    Room<Monster>* roomArray;
    unsigned int totalRooms;
public:
    int countLines(std::string filename);
    bool Dungeon::loadRoomsTXT(std::string filename);
};

#endif
