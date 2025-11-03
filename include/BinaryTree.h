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

    int get_size() { return size; }

private:
    BinNode<T>* head = nullptr;
    int size = 0;
};


#endif

