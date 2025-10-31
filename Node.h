//Carlos Carreon A01665778
//header file where nodes attributes and methods are declared
//created on 09.10.25, last modified 20.10.25
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data;
    Node<T>* left;
    Node<T>* right;
public:
    Node(const T& v): data(v), left(nullptr), right(nullptr){}
    Node<T>* getLeft();
    void setLeft(Node<T>* node);
    Node<T>* getRight();
    void setRight(Node<T>* node);
    T getData();
    void setData(T& v);


};

#include "Node.tpp"

#endif
