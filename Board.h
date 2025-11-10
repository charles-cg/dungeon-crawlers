//
// Created by MATEO HERNANDEZ on 03/11/25.
//

#ifndef BOARD_H
#define BOARD_H


template <typename T>
class Board {
private:
    int n;
    int count;
    T* vertex;
    int** Board; // This is the matrix
    int indexOf(cont T& v) const;
public:
    Graph(int capacity): n(capacity), count(0) {
          vetrex = new T[n];
          Board = new int*[n];
          for (int i = 0; i < n; i++) {
               Board[i] = new int[n];
               for (int j = 0; j < n; j++) {
                    Board[i][j] = 0;
               }
          }
    }

~Graph() {
for (int i = 0; i < n; i++) {
delete[] Board[i];
}
delete[] Board;
delete[] vetrex;
}
bool addVertex(const T& v);
bool addEdge(const T& u, const T& v, int weight = 1, bool directed = false);
};



#endif //BOARD_H
