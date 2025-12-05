#pragma once
#include "Edge.h"

template <typename T>
T Edge<T>::getDestination() const {
    return destination;
}

template <typename T>
int Edge<T>::getWeight() const {
    return weight;
}