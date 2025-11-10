//
//
//
#ifndef BOARD_H
#define BOARD_H


template <typename T>
class Board {
private:
    int n; // max capacity
    int count; // number of nodes used
    T* rooms;
    int** matrix;

    int indexOf(const T& value) const;
public:
    Board(int capacity) : n(capacity), count(0) {
        rooms = new T[n];
        matrix = new int*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    ~Board();

    bool addRoom(const T& value);
    bool addEdge(const T& from, const T& to, int weight = 1, bool directed = false);

    void printGraph() const;
    T* getRoomsArray();
};

#include "Board.tpp"  

#endif //BOARD_H
