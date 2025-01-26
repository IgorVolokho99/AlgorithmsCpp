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

template <typename T>
class OneLinkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    
    OneLinkedList() : head(nullptr), tail(nullptr) {};
    ~OneLinkedList() {};
    bool is_empty() {
        return head == nullptr;
    };
};

#endif