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

template <typename T>
int Vertex<T>::getDistance() const {
    return distance;
}

template <typename T>
void Vertex<T>::setDistance(int dist) {
    this->distance = dist;
}

template <typename T>
T Vertex<T>::getParent() const {
    return parent;
}

template <typename T>
void Vertex<T>::setParent(const T& p) {
    this->parent = p;
}
