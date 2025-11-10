//
// Created by MATEO HERNANDEZ on 10/11/25.
//

#pragma once
#include "Dungeon.h"

template <typename T>
void Dungeon<T>::loadBoard() {
codexTree = codex.getCodexTree();
Room room1 = ;
board.addRoom();
cockatrice = *codexTree.search("M3");
board.addRoom(cockatrice);
goblin = *codexTree.search("M5");
board.addRoom(goblin);
banshee = *codexTree.search("M2");
board.addRoom(banshee);
angel = *codexTree.search("M1");
board.addRoom(angel);
}
