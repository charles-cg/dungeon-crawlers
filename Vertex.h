#ifndef VERTEX_H
#define VERTEX_H

#include "LinkedList.h"
#include "Edge.h"

template <typename T>
class Vertex {
private:
    T data;

    bool visited;
    int distance;
    T parent;
    
    LinkedList<Edge<T>> adj;

public:
    Vertex(const T& v): data(v), distance(0), parent(T()) {
        visited=false;
    }

    friend ostream& operator<<(ostream& out, const Vertex& v) {
        out<<v.getData();
        return out;
    }

    bool operator==(const Vertex<T>& v) {
        return data==v.getData();
    }

    bool operator>(const Vertex<T>& v) const {
        return distance > v.distance;
    }

    T getData() const;

    T& getData();

    bool isVisited() const;

    void setVisited(bool visited);

    void addAdjacent(const Vertex<T>& vertex, const int& weight);

    bool hasAdjacent(const Vertex<T>& vertex);

    const LinkedList<Edge<T>>& getAdj() const;

    int getDistance() const;
    void setDistance(int dist);
    T getParent() const;
    void setParent(const T& p);
};

#include "Vertex.tpp"
#endif