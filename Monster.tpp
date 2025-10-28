#pragma once
#include "Monster.h"

// setter methods

void Monster::setId(const unsigned int& id) {
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


void Monster::setSpawnChance(const int& spawnChance) {
    this->spawnChance = spawnChance;
}


void Monster::setReward(const int& reward) {
    this->reward = reward;
}

// Getter methods

unsigned int Monster::getId() {
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
int Monster::getSpawnChance() {
    return spawnChance;
}
int Monster::getReward() {
    return reward;
}