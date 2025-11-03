#include "Monster.h"

Monster::Monster() {
    id = "";
    name = "";

    hp = 0;
    atk = 0;
    def = 0;

    accuracy = 0;
    reward = 0;
}

Monster::~Monster() {
    
}

// setter methods

void Monster::setId(const std::string& id) {
    this->id = id;
}


void Monster::setName(const std::string& name) {
    this->name = name;
}


void Monster::setHp(const int& hp) {
    this->hp = hp;
}


void Monster::setAtk(const int& atk) {
    this->atk = atk;
}


void Monster::setDef(const int& def) {
    this->def = def;
}


void Monster::setAccuracy(const float& accuracy) {
    this->accuracy = accuracy;
}


void Monster::setReward(const float& reward) {
    this->reward = reward;
}

// Getter methods

std::string Monster::getId() {
    return id;
}
std::string Monster::getName() {
    return name;
}
int Monster::getHp() {
    return hp;
}
int Monster::getAtk() {
    return atk;
}
int Monster::getDef() {
    return def;
}
float Monster::getAccuracy() {
    return accuracy;
}
float Monster::getReward() {
    return reward;
}