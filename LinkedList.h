//Carlos Carreon A01665778
//h file declaring the LinkedList class
//created on 30.09.25, last modified 02.10.25
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListNode.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head; //pointer to first Node
    unsigned int n; //num of elements (size)
public:
    LinkedList();
    ~LinkedList();
    unsigned int size() const;
    void pushBack(const T& value);

    bool empty() const;
    void print() const;

    void clear();
    bool remove(const T& value);
    
    void pushFront(const T& value);
    bool insert(unsigned int index, const T& value);
    T elementAt(unsigned int index);

    Node<T>* search(const T& value) const;

    Node<T>* getHead(); // method for head that can be modified
    const Node<T>* getHead() const; // read only method for head
};

#include "LinkedList.tpp"
#endif //LINKEDLIST_H
