#include "Dungeon.h"
#include <iostream>

int main() {
    Dungeon dungeon;
    
    bool flag = dungeon.loadRoomData();
    dungeon.loadPathData();

    dungeon.printBoard();

    return 0;
}