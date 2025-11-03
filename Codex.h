#ifndef CODEX_H
#define CODEX_H
#include "AVL.h"
#include "Monster.h"
#pragma once

#define MONSTERS_TXT "monsters.txt"


class Codex {
private:
    int totalMonsters;
    AVL<Monster> codexTree;

    bool loadMonsterTXT(std::string filename);

    int countLines(std::string filename);

public:
    Codex(): totalMonsters(0){}
    ~Codex();

    bool loadMonsterData();
};

#endif