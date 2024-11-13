#include "BinaryTree.h"
#include <iostream>

Node::Node(int value) : value(value), left(nullptr), right(nullptr) {};

void Node::set_left(Node* node) {
    left = node;
}

void Node::set_right(Node* node) {
    right = right;
}

BinaryTree::BinaryTree() : head(nullptr) {};

bool BinaryTree::is_empty() const {
    return (head == nullptr) ? true : false;
}

