#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <typename T>
class BinNode {
public:
    BinNode(const T& value) : value(value), left(nullptr), right(nullptr) {};

private:
    T value;
    BinNode* left;
    BinNode* right;
};


template <typename T>
class BinaryTree {
    public:
    BinaryTree() {};

    bool is_empty() {
        return head == nullptr ? true : false;
    }

private:
    BinNode<T>* head = nullptr;
};


#endif

