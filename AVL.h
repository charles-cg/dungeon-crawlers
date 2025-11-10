#ifndef AVL_H
#define AVL_H
#include <iostream>
#include "Node.h"

template <typename T>
class AVL {
private:
    Node<T>* root;

    void print(const int& r, const int& c, int& height, std::string** matrix, Node<T>* node);

    // utility methods
    int height(Node<T>* node) const;
    int balanceFactor(Node<T>* node) const;
    int maxValue(int a, int b) const;

    // rotations
    Node<T>* rotateRight(Node<T>* node);
    Node<T>* rotateLeft(Node<T>* node);
    Node<T>* rotateLeftRight(Node<T>* node);
    Node<T>* rotateRightLeft(Node<T>* node);

    Node<T>* insert(Node<T>* node, const T& value);

    Node<T>* remove(Node<T>* node, const T& value);

    void searchPath(Node<T>* node, const T& value);

    void clear(Node<T>* node);

public:
    AVL(): root(nullptr){}
    ~AVL();
    void insert(const T& value);
    void clear();
    void print();
    void remove(const T& value);

    void searchPath(const T& value);

    Node<T>* search(const T& value);
};

#include "AVL.tpp"

#endif