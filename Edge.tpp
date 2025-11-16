#pragma once
#include "Edge.h"

template <typename T>
T Edge<T>::getDestination() {
    return destination;
}

template <typename T>
int Edge<T>::getWeight() {
    return weight;
}