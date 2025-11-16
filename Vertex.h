#ifndef VERTEX_H
#define VERTEX_H

#include "LinkedList.h"
#include "Edge.h"

template <typename T>
class Vertex {
private:
    T data;

    bool visited;
    
    LinkedList<Edge<T>> adj;

public:
    Vertex(const T& v): data(v) {
        visited=false;
    }

    friend ostream& operator<<(ostream& out, const Vertex& v) {
        out<<v.getData();
        return out;
    }

    bool operator==(const Vertex<T>& v) {
        return data==v.getData();
    }

    T getData() const;

    bool isVisited() const;

    void setVisited(bool visited);

    void addAdjacent(const Vertex<T>& vertex, const int& weight);

    bool hasAdjacent(const Vertex<T>& vertex);

    const LinkedList<Edge<T>>& getAdj() const;
};

#include "Vertex.tpp"
#endif