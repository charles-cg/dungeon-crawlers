//Carlos Carreon A01665778
//tpp file implementing LinkedList methods
//created on 30.09.25, last modified 02.10.25
#pragma once
#include <exception>
#include <iostream>
#include "LinkedList.h"
using namespace std;

// Default size is 0 (no elements)
template<typename T>
LinkedList<T>::LinkedList():head(nullptr), n(0){}

// Destructor
template<typename T>
LinkedList<T>::~LinkedList() {
    clear(); // deletes all nodes
}

// Returns true if there are no elements, false if there are.
template<typename T>
bool LinkedList<T>::empty() const {
    return n == 0; 
}

// Prints all linked list nodes' data.
template<typename T>
void LinkedList<T>::print() const{
    if (empty()) {
        cout<< "Empty List!" <<endl;
    }else {
        const Node<T>* current= head;
        cout<<"[";
        while (current) {
            cout << " " << current->getData() << " ->";
            current = current->getNext();
        }
        cout<< "]" <<endl;
    }

}

// Inserts a Node at the end of the list with a specified value for data.
template<typename T>
void LinkedList<T>::pushBack(const T &value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    }else {
        Node<T>* current = head;
        while (current->getNext()) {
            current = current->getNext();
        }
        current->setNext(newNode); // Loops trhough the whole list to insert node at the end.
    }
    ++n;
}

// Inserts a node with a specified value for data on the specified index.
template<typename T>
bool LinkedList<T>::insert(unsigned int index, const T &value) {
    if (index > n) return false;
    if (index == 0) { // If there is no nodes, insert using pushBack
        pushBack(value);
        return true;
    }
    Node<T>* current = head;
    for (int i = 0;i < index - 1;i++) { // Loop until one before the desired index position
        current = current->getNext();
    }
    Node<T>* newNode = new Node<T>(value);
    newNode->setNext(current->getNext()); // newNode points to the next node
    current->setNext(newNode); // current node now points to the newNode
    ++n; // add 1 to the size
    return true;
}

// deletes all nodes inside the linked list
template <typename T>
void LinkedList<T>::clear() {
    if (head) { // deletes only if there are nodes
        Node<T>* current = head;
        while (current != nullptr) {
            head = current->getNext(); 
            delete current; // deletes current and moves to the next one
            current = head;
            n--;
        }
        delete current;
        current = nullptr;
    } else { // if there are no nodes
        return;
    }
}

// Inserts a node at the start.
template <typename T>
void LinkedList<T>::pushFront(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    } else {
        newNode->setNext(head); // new node points to current head
        head = newNode; // new node is now the head
    }
    ++n;
}

// Returns th value specified by the index
template <typename T>
T LinkedList<T>::elementAt(unsigned int index) {
    Node<T>* current = head;
    for (int i = 0; i < index; i++) { // Loops until the inputted index
        current = current->getNext();
    }
    return current->getData(); // returns value of that node
}

// Searches an specific value and deletes its node
template <typename T>
bool LinkedList<T>::remove(const T& value) {
    if (!head) {
        std::cout << "No elements to remove, list is empty" << std::endl;
        return false;
    } else if (head->getData() == value) { // handles edge case of the value being on the first node
        Node<T>* temp = head;
        head = temp->getNext();
        delete temp;
        temp = nullptr;
        --n;
        return true;
    } else {
        Node<T>* current = head->getNext();
        Node<T>* previous = head;
        while (current != nullptr) { // loop through all the nodes
            if (current->getData() == value) { 
                previous->setNext(current->getNext()); // previous node now points to the next node
                delete current; //deletes current
                current = nullptr;
                --n;
                return true;
            }
            previous = current; // if values not equal
            current = current->getNext();
        }
        std::cout << "No element found to remove" << std::endl;
        return false;
    }
}

// Returns size of the linked list
template <typename T>
unsigned int LinkedList<T>::size() const{
    return n;
}

template <typename T>
Node<T>* LinkedList<T>::search(const T& value) const {
    Node<T>* current = head;
    while (current) {
        if (current->getData() == value) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

template <typename T>
Node<T>* LinkedList<T>::getHead() {
    return head;
}

template <typename T>
const Node<T>* LinkedList<T>::getHead() const {
    return head;
}