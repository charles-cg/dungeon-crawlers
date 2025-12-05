//
// Created by MATEO HERNANDEZ on 04/12/25.
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


template <typename T>
class PriorityQueue {
private:
    LinkedList<T> list;

public:
    PriorityQueue() = default;
    void push(const T& value);
    void pop();
    T top() const;
    bool empty() const;
    int size() const;
};

#include "PriorityQueue.tpp"

#endif //PRIORITYQUEUE_H
