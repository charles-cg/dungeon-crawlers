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
    T creature;
    Hero* hero;
public:
    Room();
    ~Room();

    void setId(const std::string& id);
    void setName (const std::string& name);
    void setEncounterChance(const float& encounterChance);
    void setWasVisited(bool& wasVisited);
    void setCreature(const T& creature);
    void setHero(Hero* hero);

    std::string getId();
    std::string getName();
    float getEncounterChance();
    bool getWasVisited();
    T getCreature();
    Hero* getHero();

    bool operator<(const Room<T>& otherRoom) const {
        return this->id < otherRoom.id;
    }

    bool operator>(const Room<T>& otherRoom) const {
        return this->id > otherRoom.id;
    }

    bool operator==(const Room<T>& otherRoom) const {
        return this->id == otherRoom.id;
    }

    friend std::ostream& operator<<(std::ostream& os, const Room<T>& otherRoom) {
        os << otherRoom.id;
        return os;
    }
};

#include "Room.tpp"

#endif