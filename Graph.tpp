#pragma once
#include "Graph.h"
#include <iostream>
using namespace std;

template <typename T>
Node<Vertex<T>>* Graph<T>::findVertexNode(const T& v){
    Node<Vertex<T>>* current = vertices.getHead();
    while (current) {
        if (current->getData().getData() == v) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

template <typename T>
bool Graph<T>::addVertex(const T& v) {
    if (findVertexNode(v) != nullptr) {
        return false;
    }
    Vertex<T> vertex(v);
    vertices.pushBack(vertex);
    return true;
}

template <typename T>
bool Graph<T>::addEdge(const T& from,const T& to, const int& weight, const bool directed) {
    Node<Vertex<T>>* originNode = findVertexNode(from);
    Node<Vertex<T>>* toNode = findVertexNode(to);
    if (!originNode || !toNode) {
        return false;
    }

    if (!originNode->getData().hasAdjacent(toNode->getData())) {
        originNode->getData().addAdjacent(toNode->getData(), weight);
    }
    if (!directed) {
        if (!toNode->getData().hasAdjacent(originNode->getData())) {
            toNode->getData().addAdjacent(originNode->getData(), weight);
        }
    }
    return true;
}

template <typename T>
void Graph<T>::print() const {
    const Node<Vertex<T>>* current = vertices.getHead();
    while (current) {
        cout << current->getData().getData() << ": ";
        current->getData().getAdj().print();
        current = current->getNext();
        cout << endl;
    }
}