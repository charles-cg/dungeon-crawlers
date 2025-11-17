//Carlos Carreon A01665778
//tpp file implementing Node methods
//created on 30.09.25, last modified 02.10.25
#pragma once
#include "ListNode.h"

template <typename T>
ListNode<T>::~ListNode() {
    
}

template <typename T>
ListNode<T>::ListNode(const T& v): data(v), next(nullptr){}

template <typename T>
const T& ListNode<T>::getData() const {
    return data;
}

template <typename T>
T& ListNode<T>::getData() {
    return data;
}

template <typename T>
ListNode<T>* ListNode<T>::getNext() const {
    return next;
}

template <typename T>
void ListNode<T>::setNext(ListNode* node) {
    next = node;
}
