// 
// 
// 
#pragma once
#include "Square.h"

// Setter Methods
template <typename T>
void Square<T>::setId(const int& id) {
    this->id = id;
}

template <typename T>
void Square<T>::setName(const std::string& name) {
    this->name = name;
}

template <typename T>
void Square<T>::setEncounterChance(const int& encounterChance) {
    this->encounterChance = encounterChance;
}

template <typename T>
void Square<T>::setWasVisited(bool& wasVisited) {
    this->wasVisited = wasVisited;
}

template <typename T>
void Square<T>::setPrev(Square<T>* prev) {
    this->prev = prev;
}

template <typename T>
void Square<T>::setNext(Square<T>* next) {
    this->next = next;
}

// Getter methods
template <typename T>
unsigned int Square<T>::getId() {
    return id;
}

template <typename T>
std::string Square<T>::getName() {
    return name;
}

template <typename T>
unsigned int Square<T>::getEncounterChance() {
    return encounterChance;
}

template <typename T>
bool Square<T>::getWasVisited() {
    return wasVisited;
}

template <typename T>
Square<T>* Square<T>::getPrev() {
    return prev;
}

template <typename T>
Square<T>* Square<T>::getNext() {
    return next;
}