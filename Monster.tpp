#pragma once
#include "Monster.h"

// setter methods
template <typename T>
void setId(const unsigned int& id) {
    this->id = id;
}

template <typename T>
void setName(const std::string& name) {
    this->name = name;
}

template <typename T>
void setHp(const int& hp) {
    this->hp = hp;
}

template <typename T>
void setAtk(const int& atk) {
    this->atk = atk;
}

template <typename T>
void setDef(const int& def) {
    this->def = def;
}

template <typename T>
void setSpawnChance(const int& spawnChance) {
    this->spawnChance = spawnChance;
}

template <typename T>
void setReward(const int& reward) {
    this->reward = reward;
}