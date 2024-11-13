#ifndef BINARYTREE_H
#define BINARYTREE_H

class Node {
public:
    Node(int);
    void set_left(Node* node);
    void set_right(Node* node);

private:
    Node* left;
    Node* right;
    int value;
};

class BinaryTree {
public:
    BinaryTree();
    bool is_empty() const;

private:
    Node* head;
    int depth;
};

#endif