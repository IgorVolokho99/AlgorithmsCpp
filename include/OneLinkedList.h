#ifndef ONELINKEDLIST_H
#define ONELINKEDLIST_H

template <typename T>
class Node {
public:
    T value;
    Node* next;

    Node(const T& value) : value(value), next(nullptr) {};

    ~Node() {};
};

#endif