#ifndef ROOM_H
#define ROOM_H
#include <string>
#include "Monster.h"

template <typename T>
class Room {
private:
    unsigned int id;
    std::string name;
    float encounterChance; // chance ranges from 0 - 1
    bool wasVisited; // flag indicating if a square has been visited
    Room<T>* prev;
    Room<T>* next;
    Monster monster;
public:
    Room();
    ~Room();

    void setId(const unsigned int& id);
    void setName (const std::string& name);
    void setEncounterChance(const float& encounterChance);
    void setWasVisited(bool& wasVisited);
    void setPrev(Room<T>* prev);
    void setNext(Room<T>* next);
    void setMonster(Monster monster);

    unsigned int getId();
    std::string getName();
    float getEncounterChance();
    bool getWasVisited();
    Room<T>* getPrev();
    Room<T>* getNext();
    Monster getMonster();
};

#include "Room.tpp"

#endif