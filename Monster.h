#ifndef MONSTER_H
#define MONSTER_H
#include <string>

class Monster {
private:
    unsigned int id;
    std::string name;

    int hp;
    int atk;
    int def;

    int encounterChance;
    int reward;
};

#endif