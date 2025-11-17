#include "Dungeon.h"
#include <iostream>

int main() {
    Dungeon dungeon;
    
    bool flag = dungeon.loadRoomData();
    dungeon.loadPathData();

    dungeon.setStartingRoom();

    dungeon.printBoard();

    dungeon.showNeghboringRooms();

    return 0;
}