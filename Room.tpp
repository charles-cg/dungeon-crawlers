// 
// 
// 
#pragma once
#include "Room.h"

template <typename T>
Room<T>::Room() {
    id = "";
    name = "";
    encounterChance = 0;
    wasVisited = false;
    hero = nullptr;
}

template <typename T>
Room<T>::~Room() {
    
}

// Setter Methods
template <typename T>
void Room<T>::setId(const std::string& id) {
    this->id = id;
}

template <typename T>
void Room<T>::setName(const std::string& name) {
    this->name = name;
}

template <typename T>
void Room<T>::setEncounterChance(const float& encounterChance) {
    this->encounterChance = encounterChance;
}

template <typename T>
void Room<T>::setWasVisited(const bool& wasVisited) {
    this->wasVisited = wasVisited;
}

template <typename T>
void Room<T>::setCreature(const T& creature) {
    this->creature = creature;
}

template <typename T>
void Room<T>::setHero(Hero* hero) {
    this->hero = hero;
}


// Getter methods
template <typename T>
std::string Room<T>::getId() {
    return id;
}

template <typename T>
std::string Room<T>::getName() {
    return name;
}

template <typename T>
float Room<T>::getEncounterChance() {
    return encounterChance;
}

template <typename T>
bool Room<T>::getWasVisited() {
    return wasVisited;
}

template <typename T>
T Room<T>::getCreature() {
    return creature;
}

template <typename T>
Hero* Room<T>::getHero() {
    return hero;
}