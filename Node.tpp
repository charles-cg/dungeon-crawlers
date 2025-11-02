#pragma once
#include "Node.h"

template <typename T>
T Node<T>::getData() {
    return data;
}

template <typename T>
Node<T>* Node<T>::getLeft() {
    return left;
}

template <typename T>
Node<T>* Node<T>::getRight() {
    return right;
}

template <typename T>
int Node<T>::getHeight() {
    return height;
}

template <typename T>
void Node<T>::setData(const T& value) {
    data = value;
}

template <typename T>
void Node<T>::setLeft(Node<T>* node) {
    left = node;
}

template <typename T>
void Node<T>::setRight(Node<T>* node) {
    right = node;
}

template <typename T>
void Node<T>::setHeight(const int& height) {
    this->height = height;
}