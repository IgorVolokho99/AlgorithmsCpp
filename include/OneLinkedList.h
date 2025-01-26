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

    void push_back(T data) {
        Node<T>* new_node = new Node(data);
        if (is_empty()) {
            head = tail = new_node;
        } else {
            new_node->next = tail;
            tail = new_node;
        }
    }

    void push_front(T data) {
        Node<T>* new_node = new Node(data);

        if (is_empty()) {
            head = tail = new_node;
        } else {
            head.next = new_node;
            head = new_node;
        }
    }
};

#endif