#pragma once
#include "Vertex.h"

template <typename T>
T Vertex<T>::getData() const{
    return data;
}

template <typename T>
bool Vertex<T>::isVisited() const {
    return visited;
}

template <typename T>
void Vertex<T>::setVisited(bool visited) {
    this->visited = visited;
}

template <typename T>
void Vertex<T>::addAdjacent(const Vertex<T>& vertex, const int& weight) {
    Edge<T> edge(vertex.getData(), weight);
    adj.pushBack(edge);
}

template <typename T>
bool Vertex<T>::hasAdjacent(const Vertex<T>& vertex) {
    Edge<T> searchEdge(vertex.getData(), 0);
    return adj.search(searchEdge) != nullptr;
}

template <typename T>
const LinkedList<Edge<T>>& Vertex<T>::getAdj() const {
    return adj;
}

template <typename T>
T& Vertex<T>::getData() {
    return data;
}
