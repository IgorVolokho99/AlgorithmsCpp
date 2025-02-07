#ifndef ONELINKEDLIST_H
#define ONELINKEDLIST_H

#include <stdexcept>
#include <iostream>

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
            head->next = new_node;
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

    // Если пустой - рейзим индексеррор.
    // Если индекс ноль - вызываем пуш фронт.
    // Иначе цикл вайл до

    void insert(int index, T data) {
        if (is_empty()) {
            throw std::out_of_range("List is empty, cannot insert");
            return;
        }
        else if (index == 0) {
            push_front(data);
            return;
        }
        
        Node<T>* current_node = head;
        int current_index = 0;
        while (current_node->next != nullptr && current_index != index - 1) {
            current_node = current_node->next;
            ++current_index;
        }

        if (current_index != index - 1) {
            throw std::out_of_range("List is empty, cannot insert");
        } else {
            Node<T>* new_node = new Node(data);
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
    }

    // Если is_empty, то бросаем исключение
    // Если head->value == data, то pop_front + return
    // Иначе вайлом ищим.


    void remove(T data) {
        if (is_empty()) return;
        if (head->value == data) {
            pop_front();
            return;
        }

        Node<T>* current_node = head;

        while (current_node->next != nullptr && current_node->next->value != data)
            current_node = current_node->next;

        if (current_node->next == nullptr) throw std::runtime_error("Value not found in the list.");
        if (current_node->next == tail) {
            pop_back();
            return;
        }
        Node<T>* deleted_node = current_node->next;
        current_node->next = current_node->next->next;

        delete deleted_node;
    }

    int find(T data) {
        if (is_empty()) return -1;

        Node<T>* current_node = head;
        int index = 0;
        while (current_node->value != data && current_node != tail) {
            current_node = current_node->next;
            ++index;
        } 
        if (current_node->value != data) return -1;

        return index;
    }

    T get(int index) {
        if (is_empty()) 
            throw std::out_of_range("List is empty, indexerror.");
        // if (index < 0)
        //     throw std::runtime_error("")

        int current_index = 0;
        Node<T>* current_node = head;
        while (current_index < index && current_node != nullptr) {
            current_node = current_node->next;
            ++current_index;
        }

        if (current_node == nullptr || current_index != index) throw std::runtime_error("IndexError.");

        return current_node->value;
    }
    
};

#endif