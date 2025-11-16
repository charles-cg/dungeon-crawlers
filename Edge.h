#ifndef EDGE_H
#define EDGE_H

#include <iostream>

template <typename T>
class Edge {
private:
    T destination;
    int weight;
public:
    Edge(const T& dest, int w) : destination(dest), weight(w) {}

    T getDestination();

    int getWeight();

    bool operator==(const Edge<T>& edge) const {
        return destination == edge.destination;
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge<T>& edge) {
        os << "(" << edge.destination << ", " << edge.weight << ")";
        return os;
    }
};

#include "Edge.tpp"

#endif