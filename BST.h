//Carlos Carreon A01665778
//header file where BST attributes and methods are declared
//created on 09.10.25, last modified 20.10.25
#ifndef BST_H
#define BST_H
#include "Node.h"
#include <string>
template <typename T>
class BST {
private:
    Node<T>* root;
    bool search(Node<T>* root, const T& v) const;
    void visit(Node<T>* node) const;
    void inOrder(Node<T>* node) const;
    void postOrder(Node<T>* node) const;
    void preOrder(Node<T>* node) const;
    Node<T>* remove(Node<T>* node, const T& value);
    int height(Node<T>* node);
    bool ancestors(Node<T>* node, const T& value);
    int whatLevelAmI(Node<T>* node, const T& value);
    void clear(Node<T>* node);
    void print(const int& r, const int& c, int& height, std::string** matrix, Node<T>* node);
public:
    BST();
    ~BST();
    bool isEmpty() const;
    void print();
    void clear();
    void insert(const T& v);
    bool search(const T& v) const;
    void inOrder() const;
    void postOrder() const;
    void preOrder() const;
    void remove(const T& v);
    int height();
    bool ancestors(const T& value);
    int whatLevelAmI(const T& value);
};

#include "BST.tpp"
#endif
