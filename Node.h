#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data;
    Node<T>* left;
    Node<T>* right;
    int height;
public:
    explicit Node(const T& v) : data(v), left(nullptr), right(nullptr), height(1) {}
    T getData();
    Node<T>* getLeft();
    Node<T>* getRight();
    int getHeight();

    void setData(const T& value);
    void setLeft(Node<T>* node);
    void setRight(Node<T>* node);
    void setHeight(const int& value);
};

#include "Node.tpp"

#endif