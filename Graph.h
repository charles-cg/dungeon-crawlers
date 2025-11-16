#ifndef GRAPH_H
#define GRAPH_H
#include "LinkedList.h"
#include "Vertex.h"

template <typename T>
class Graph {
private:
    LinkedList<Vertex<T>> vertices;

    ListNode<Vertex<T>>* findVertexNode(const T& v);

public:
    Graph() = default;

    bool addVertex(const T& v);

    bool addEdge(const T& from, const T& to, const int& weight = 1, const bool directed = false);

    void print() const;
};

#include "Graph.tpp"

#endif
