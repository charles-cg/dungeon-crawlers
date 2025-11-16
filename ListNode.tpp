//Carlos Carreon A01665778
//tpp file implementing Node methods
//created on 30.09.25, last modified 02.10.25
#pragma once
#include "ListNode.h"

template <typename T>
Node<T>::Node(const T& v): data(v), next(nullptr){}

template <typename T>
const T& Node<T>::getData() const {
    return data;
}

template <typename T>
T& Node<T>::getData() {
    return data;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template <typename T>
void Node<T>::setNext(Node* node) {
    next = node;
}
