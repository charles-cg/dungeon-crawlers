#include "Dungeon.h"
#include <iostream>

int main() {
    Dungeon dungeon;
    
    bool flag = dungeon.loadRoomData();
    dungeon.loadPathData();

    return 0;
}