#include "BinaryTree.h"
#include <iostream>

Node::Node(int value) : value(value), left(nullptr), right(nullptr) {};

void Node::set_left(Node* node) {
    left = node;
}

void Node::set_right(Node* node) {
    right = node;
}

int Node::get_value() {
    return value;
}

Node* Node::get_right() {
    return right;
}

Node* Node::get_left() {
    return left;
}

BinaryTree::BinaryTree() : head(nullptr) {};

bool BinaryTree::is_empty() const {
    return (head == nullptr) ? true : false;
}


Node* BinaryTree::get_head() const {
    return head;
}

void BinaryTree::append(int value) {
    Node* node = new Node(value);
    if (this->is_empty()) 
        this->head = node;
    else
        this->find_position(head, node);
}

void BinaryTree::find_position(Node* current_node, Node* node) {
    if (current_node->get_value() == node->get_value())
        return;

    if (current_node->get_right() == nullptr && node->get_value() > current_node->get_value()) {
        current_node->set_right(node);
        return;
    }
    else if (current_node->get_left() == nullptr && node->get_value() < current_node->get_value()) {
        current_node->set_left(node);
        return;
    }
        
    if (node->get_value() > current_node->get_value())
        find_position(current_node->get_right(), node);
    else 
        find_position(current_node->get_left(), node);
}
