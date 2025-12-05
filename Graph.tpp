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

// dijkstra algorithm's implementation was provided by professor Andrés Torres
template <typename T>
void Graph<T>::dijkstra(const T& startVertex) {
    Node<Vertex<T>>* current = vertices.getHead();
    while (current) {
        current->getdata.setDistance(std::numeric_limits<int>::max());
        current->getdata.setVisited(false);
        current->getdata.setParent(T()); // Reset parent to default
        current = current->next;
    }

    Node<Vertex<T>>* startNode = findVertexNode(startVertex);
    if (!startNode) {
        std::cout << "Initial vertex not found" << std::endl;
        return;
    }

    startNode->getData().setDistance(0);

    PriorityQueue<Vertex<T>> pq;
    pq.push(startNode->getData());

    while (!pq.empty()) {
        Vertex<T> topVertex = pq.top();
        pq.pop();

        int currentDist = topVertex.getDistance();
        T u = topVertex.getData();

        Node<Vertex<T>>* uNode = findVertexNode(u);
        if (!uNode) continue;

        if (currentDist > uNode->getData().getDistance()) continue;

        uNode->getData().setVisited(true);

        Node<Edge<T>>* edgeNode = uNode->getData().getAdj().getHead();
        while (edgeNode) {
            T v = edgeNode->getData().getDest();
            int staminaCost = edgeNode->getData().getWeight(); // In our case, the weight is expressed in stamina cost

            Node<Vertex<T>>* vNode = findVertexNode(v);
            if (vNode) {
                int distU = uNode->getData().getDistance();
                if (distU != std::numeric_limits<int>::max() &&
                    distU + staminaCost < vNode->getData().getDistance()) {

                    vNode->getData().setDistance(uNode->data.getDistance() + staminaCost);
                    vNode->getData().setParent(u);
                    pq.push(vNode->getData());
                }
            }
            edgeNode = edgeNode->getNext();
        }
    }

    std::cout << "Dijkstra from " << startVertex << ":" << std::endl;
    current = vertices.getHead();
    while (current) {
        std::cout << "Vertex: " << current->data.getData() << ", distance: ";
        if (current->data.getDistance() == std::numeric_limits<int>::max()) {
            std::cout << "INF";
        } else {
            std::cout << current->data.getDistance() << ", father: " << current->data.getParent();
        }
        std::cout << std::endl;
        current = current->next;
    }
}

template<typename T>
LinkedList<T> Graph<T>::getShortestPath(const T &startVertex, const T &endVertex) {
    LinkedList<T> path;

    ListNode<Vertex<T>>* endNode = findVertexNode(endVertex);

    if (!endNode) {
        std::cout << "Last vertex not found" << std::endl;
        return path;
    }

    if (endNode->geData().getDistance() == std::numeric_limits<int>::max()) {
        std::cout << "No existing path" << std::endl;
        return path;
    }

    T current = endVertex;

    while (true) {
        path.pushFront(current);

        if (current == startVertex) {
            break;
        }
        ListNode<Vertex<T>>* currentNode = findVertexNode(current->data.getData());
        if (!currentNode) {
            break;
        }
        current = currentNode->getData().getParent();
    }
    return path;
}
