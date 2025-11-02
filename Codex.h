#ifndef CODEX_H
#define CODEX_H
#include "AVL.h"
#include "Monster.h"


class Codex {
private:
    int totalMonsters;
    AVL<Monster> codexTree;

    bool loadMonsterTXT(std::string filename);

public:
    Codex();
    ~Codex();

    bool loadMonsterData();
};

#endif