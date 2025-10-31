#ifndef CODEX_H
#define CODEX_H
#include "BST.h"

template <typename T>
class Codex {
private:
    BST<T> tree;

    bool loadMonsterTXT(std::string filename);

public:
    Codex();
    ~Codex();

    bool loadMonsterData();
};

#endif