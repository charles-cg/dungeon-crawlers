#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Dungeon.h"

class GameController {
private:
    Dungeon dungeon;
public:
    GameController() {
        dungeon.loadRoomData();
        dungeon.loadPathData();
        dungeon.setStartingRoom();
    }
    void handleHeroMovement();
};

#endif