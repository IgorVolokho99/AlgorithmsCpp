#ifndef ONELINKEDLIST_H
#define ONELINKEDLIST_H

#include <stdexcept>

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
            // new_node->next = tail;
            tail->next = new_node;
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

    T pop_front() {
        if (is_empty())
            throw std::out_of_range("List is empty, cannot pop");
        
        T value = head->value;
        Node<T>* temp = head;

        if (head == tail) 
            head = tail = nullptr;
        else
            head = head->next;

        delete temp;
        return value;
    }

    T pop_back() {
        if (is_empty()) 
            throw std::out_of_range("List is empty, cannot pop");
        if (head == tail) {
            T value = head->value;
            head = tail = nullptr;
            return value;
        }

        Node<T>* current_node = head;
        while (current_node->next != tail)
            current_node = current_node->next;

        T value = tail->value;
        delete tail;
        tail = current_node;
        return value;
    }

    void clear() {
        while (head != nullptr)
            pop_back();
    }

    int size() {
        Node<T>* current_node = head;
        int counter = 0;
        while (current_node != nullptr) {
            ++counter;
            current_node = current_node->next;
        }

        return counter;
    }

};

#endif