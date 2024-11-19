#ifndef BINARYTREE_H
#define BINARYTREE_H

class Node {
public:
    Node(int);
    void set_left(Node* node);
    void set_right(Node* node);
    int get_value();
    Node* get_left();
    Node* get_right();

private:
    Node* left;
    Node* right;
    int value;
};

class BinaryTree {
public:
    BinaryTree();
    bool is_empty() const;
    Node* get_head() const;
    void append(int);
    void find_position(Node*, Node*);

private:
    Node* head;
    int depth;
};

#endif