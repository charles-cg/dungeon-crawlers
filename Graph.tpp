#pragma once
#include "Graph.h"
#include "Node.h"
#include "PriorityQueue.h"
#include <limits>
#include <iostream>
using namespace std;

template <typename T>
Graph<T>::~Graph() {
    
}

template <typename T>
ListNode<Vertex<T>>* Graph<T>::findVertexNode(const T& v){
    ListNode<Vertex<T>>* current = vertices.getHead();
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
    ListNode<Vertex<T>>* originNode = findVertexNode(from);
    ListNode<Vertex<T>>* toNode = findVertexNode(to);
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
    const ListNode<Vertex<T>>* current = vertices.getHead();
    while (current) {
        cout << current->getData().getData() << "-> ";
        current->getData().getAdj().print();
        current = current->getNext();
        cout << endl;
    }
}

template <typename T>
const ListNode<Vertex<T>>* Graph<T>::findVertexNode(const T& v) const {
    const ListNode<Vertex<T>>* current = vertices.getHead();
    while (current) {
        if (current->getData().getData() == v) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}


template <typename T>
void Graph<T>::dijkstra(const T& startVertex) {
    Node<Vertex<T>>* current = vertices.getHead();
    while (current) {
        current->data.setDistance(std::numeric_limits<int>::max());
        current->data.setVisited(false);
        current->data.setParent(T()); // Reset parent to default
        current = current->next;
    }

    Node<Vertex<T>>* startNode = findVertexNode(startVertex);
    if (!startNode) {
        cout << "Vertice inicial no encontrado" << endl;
        return;
    }

    startNode->data.setDistance(0);

    PriorityQueue<Vertex<T>> pq;
    pq.push(startNode->data);

    while (!pq.empty()) {
        Vertex<T> topVertex = pq.top();
        pq.pop();

        int currentDist = topVertex.getDistance();
        T u = topVertex.getData();

        Node<Vertex<T>>* uNode = findVertexNode(u);
        if (!uNode) continue;

        if (currentDist > uNode->data.getDistance()) continue;

        uNode->data.setVisited(true);

        Node<Edge<T>>* edgeNode = uNode->data.getAdj().getHead();
        while (edgeNode) {
            T v = edgeNode->data.getDest();
            int weight = edgeNode->data.getWeight();

            Node<Vertex<T>>* vNode = findVertexNode(v);
            if (vNode) {
                if (uNode->data.getDistance() != std::numeric_limits<int>::max() &&
                    uNode->data.getDistance() + weight < vNode->data.getDistance()) {

                    vNode->data.setDistance(uNode->data.getDistance() + weight);
                    vNode->data.setParent(u);
                    pq.push(vNode->data);
                }
            }
            edgeNode = edgeNode->next;
        }
    }

    cout << "Dijkstra desde " << startVertex << ":" << endl;
    current = vertices.getHead();
    while (current) {
        cout << "Vertex: " << current->data.getData() << ", distancia: ";
        if (current->data.getDistance() == std::numeric_limits<int>::max()) {
            cout << "INF";
        } else {
            cout << current->data.getDistance() << ", padre: " << current->data.getParent();
        }
        cout << endl;
        current = current->next;
    }
}