#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>
#include <queue>

template <typename T>
class BinNode {
public:
    BinNode(const T& value) : value(value), left(nullptr), right(nullptr) {};

public:
    T value;
    BinNode<T>* left;
    BinNode<T>* right;
};


template <typename T>
class BinaryTree {
    public:
    BinaryTree() {};

    bool is_empty() {
        return head == nullptr;
    }

    int get_size() { return size; }

    void clear(BinNode<T>* node = nullptr) {
        if (head == nullptr) return;

        if (node == nullptr) {
            clear(head);
            head = nullptr;
            size = 0;
            return;
        }

        if (node->left) clear(node->left);
        if (node->right) clear(node->right);

        delete node;
    }

    BinNode<T>* root () {
        return head;
    }

    void insert(T value) {
        if (is_empty()) {
            head = new BinNode<T>(value);
            ++size;
            return;
        }

        std::vector<BinNode<T>*> queue = {head};

        for (size_t i = 0; i < queue.size(); ++i) {
            BinNode<T>* node = queue[i];

            if (node->left == nullptr) {
                node->left = new BinNode<T>(value);
                ++size;
                return;
            } else {
                queue.push_back(node->left);
            }

            if (node->right == nullptr) {
                node->right = new BinNode<T>(value);
                ++size;
                return;
            } else {
                queue.push_back(node->right);
            }
        }
    }
    
    void preorder() {
        preorder_impl(head);
    }

    void preorder_impl(BinNode<T>* node) {
        if (node == nullptr) return;

        std::cout << node->value << std::endl;

        preorder_impl(node->left);
        preorder_impl(node->right);
    }

    void inorder() {
        inorder_impl(head);
    }

    void inorder_impl(BinNode<T>* node) {
        if (node == nullptr) return;

        inorder_impl(node->left);
        std::cout << node->value << std::endl;
        inorder_impl(node->right);
    }

    void postoreder() {
        postoreder_impl(head);
    }

    void postoreder_impl(BinNode<T>* node) {
        if (node == nullptr) return;

        postoreder_impl(node->left);
        postoreder_impl(node->right);
        std::cout << node->value << std::endl;
    }

    void level_order() {
        level_oreder_impl();
    }

    void level_oreder_impl() {
        if (head == nullptr) return;
        
        std::queue<BinNode<T>*> q;
        q.push(head);

        while (!q.empty()) {
            BinNode<T>* node = q.front();
            q.pop();

            std::cout << node->value << std::endl;
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }
    

    ~BinaryTree() {
        clear();
    }

private:
    BinNode<T>* head = nullptr;
    int size = 0;
};


#endif

