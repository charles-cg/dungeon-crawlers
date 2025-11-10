//
//
//
#pragma once
#include "Board.h"

template <typename T>
Board<T>::~Board() {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i]
    }

    delete[] matrix;
    matrix = nullptr;
    delete[] rooms;
    rooms = nullptr;
}

template <typename T>
int Board<T>::indexOf(const T& value) const {
    for (int i = 0; i < count; i++) {
        if (rooms[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
bool Board<T>::addRoom(const T& value) {
    if (count >= n) {
        return false;
    }
    if (indexOf(value) != -1) {
        return false;
    }
    rooms[count++] = value;
    return true;
}

template <typename T>
bool Board<T>::addEdge(const T& from, const T& to, int weight = 1, bool directed = false) {
    int idxFrom = indexOf(from);
    int idxTo = indexOf(to);
    if (idxFrom == -1 || idxTo == -1) {
        return false;
    }
    matrix[idxFrom][idxTo] = weight;
    if (!directed) {
        matrix[idxTo][idxFrom] = weight;
    }
    return true;
}