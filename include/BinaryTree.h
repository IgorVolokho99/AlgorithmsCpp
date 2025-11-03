#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <typename T>
class BinNode {
public:
    BinNode(const T& value) : value(value), left(nullptr), right(nullptr) {};

public:
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

    void clear(BinNode<T>* node = nullptr) {
        if (size == 0) return;

        if (node == nullptr) {
            this->clear(head);
        } else {
            if (node->left != nullptr) this->clear(node->left);
            if (node->right !=nullptr) this->clear(node->right);
            delete this;
            size -= 1;
        }
    }

    BinNode<T>* root () {
        return head;
    }

private:
    BinNode<T>* head = nullptr;
    int size = 0;
};


#endif

