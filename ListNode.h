//Carlos Carreon A01665778
//h file declaring the node class
//created on 30.09.25, last modified 02.10.25
#ifndef LISTNODE_H
#define LISTNODE_H
template <typename T>
class Node {
private:
    T data;
    Node* next;
public:
    Node(const T& v);

    const T& getData() const; // read only method for getting data

    T& getData(); //method for getting data that can be modified

    Node* getNext() const; // read only method for getting next

    void setNext(Node* node); // method for setting next

};

#include "ListNode.tpp"
#endif //NODE_H
