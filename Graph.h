#ifndef GRAPH_H
#define GRAPH_H
#include "LinkedList.h"
#include "Vertex.h"

template <typename T>
class Graph {
private:
    LinkedList<Vertex<T>> vertices;

public:
    Graph() = default;

    ~Graph();

    bool addVertex(const T& v);

    bool addEdge(const T& from, const T& to, const int& weight = 1, const bool directed = false);

    void print() const;

    ListNode<Vertex<T>>* findVertexNode(const T& v);

    const ListNode<Vertex<T>>* findVertexNode(const T& v) const;

    void dijkstra(const T& startVertex);

    LinkedList<T> getShortestPath(const T& startVertex, const T& endVertex);
};

#include "Graph.tpp"

#endif
