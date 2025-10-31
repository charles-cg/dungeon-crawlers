//Carlos Carreon A01665778
//tpp file where nodes methods are implemented
//created on 09.10.25, last modified 20.10.25
#pragma once
#include "Node.h"

// getter methods
template <typename T>
Node<T>* Node<T>::getLeft() {
    return left;
}

template <typename T>
Node<T>* Node<T>::getRight() {
    return right;
}

template <typename T>
T Node<T>::getData() {
    return data;
}

// setter methods
template <typename T>
void Node<T>::setLeft(Node<T>* node) {
    left= node;
}

template <typename T>
void Node<T>::setRight(Node<T>* node) {
    right= node;
}

template <typename T>
void Node<T>::setData(T& v) {
    data=v;
}