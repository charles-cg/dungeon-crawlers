// 
// 
// 
#pragma once
#include "Room.h"

// Setter Methods
template <typename T>
void Room<T>::setId(const unsigned int& id) {
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
void Room<T>::setWasVisited(bool& wasVisited) {
    this->wasVisited = wasVisited;
}

template <typename T>
void Room<T>::setPrev(Room<T>* prev) {
    this->prev = prev;
}

template <typename T>
void Room<T>::setNext(Room<T>* next) {
    this->next = next;
}

template <typename T>
void Room<T>::setMonster(Monster monster) {
    this->monster = monster;
}

// Getter methods
template <typename T>
unsigned int Room<T>::getId() {
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
Room<T>* Room<T>::getPrev() {
    return prev;
}

template <typename T>
Room<T>* Room<T>::getNext() {
    return next;
}

template <typename T>
Monster Room<T>::getMonster() {
    return monster;
}