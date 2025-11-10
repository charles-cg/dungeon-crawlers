//
// Created by MATEO HERNANDEZ on 10/11/25.
//

#ifndef DUNGEON_H
#define DUNGEON_H

#include "Codex.h"

template <typename T>
class Dungeon {
private:
Hero *hero;
Board<T> board;
Codex codex;

std::cout << "Hello World" << std::endl;

public:
void loadBoard();
Dungeon() {
Hero = new hero();
codex.loadMonsterData();
}

};


#include "Dungeon.tpp"

#endif //DUNGEON_H
