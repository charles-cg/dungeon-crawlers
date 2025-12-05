#include "Entity.h"

Entity::Entity() {
    id = "";
    name = "";

    hp = 0;
    atk = 0;
    def = 0;
    maxHp = 0;
}

Entity::~Entity() {

}

// setter methods

void Entity::setId(const std::string& id) {
    this->id = id;
}

void Entity::setName(const std::string& name) {
    this->name = name;
}

void Entity::setHp(const int& hp) {
    this->hp = hp;
}


void Entity::setAtk(const int& atk) {
    this->atk = atk;
}


void Entity::setDef(const int& def) {
    this->def = def;
}

void Entity::setMaxHp(const int& maxHp) {
    this->maxHp = maxHp;
}

// getter methods
std::string Entity::getId() {
    return id;
}

std::string Entity::getName() {
    return name;
}
int Entity::getHp() {
    return hp;
}
int Entity::getAtk() {
    return atk;
}
int Entity::getDef() {
    return def;
}

int Entity::getMaxHp() {
     return maxHp;
}
