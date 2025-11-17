#ifndef HERO_H
#define HERO_H
#include "Entity.h"

class Hero : public Entity {
private:
    std::string currentRoomId;
public:
    Hero(std::string id, std::string name, int hp, int atk, int def) : currentRoomId(""),  Entity(id, name, hp, atk, def) {}
    ~Hero();

    void setCurrentRoomId(const std::string& id);

    std::string getCurrentRoomId() const;
};

#endif