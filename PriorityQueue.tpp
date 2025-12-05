//
// Created by MATEO HERNANDEZ on 04/12/25.
//
#pragma once
#include "PriorityQueue.h"


template <typename T>
void PriorityQueue<T>::push(const T& value) {
    list.pushBack(value);
}

template <typename T>
void PriorityQueue<T>::pop() {
    if (list.empty()) return;

    T maxVal = top();
    list.remove(maxVal);
}

template <typename T>
T PriorityQueue<T>::top() const {
    if (list.empty()) throw std::runtime_error("PriorityQueue is empty");

    const ListNode<T>* current = list.getHead();
    T maxVal = current->getData();

    while (current) {
        if (current->getData() > maxVal) {
            maxVal = current->getData();
        }
        current = current->getNext();
    }
    return maxVal;
}

template <typename T>
bool PriorityQueue<T>::empty() const {
    return list.empty();
}

template <typename T>
int PriorityQueue<T>::size() const {
    return list.size();
}