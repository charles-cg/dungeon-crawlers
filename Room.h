#ifndef ROOM_H
#define ROOM_H
#include <string>
#include "Monster.h"
#include "Hero.h"

#define ROOM_NUMBER_ATTRIBUTES 5

template <typename T>
class Room {
private:
    std::string id;
    std::string name;
    float encounterChance; // chance ranges from 0 - 1
    bool wasVisited; // flag indicating if a square has been visited
    Monster monster;
    Hero* hero;
public:
    Room();
    ~Room();

    void setId(const std::string& id);
    void setName (const std::string& name);
    void setEncounterChance(const float& encounterChance);
    void setWasVisited(bool& wasVisited);
    void setMonster(Monster monster);
    void setHero(Hero* hero);

    std::string getId();
    std::string getName();
    float getEncounterChance();
    bool getWasVisited();
    Monster getMonster();
    Hero* getHero();
};

#include "Room.tpp"

#endif