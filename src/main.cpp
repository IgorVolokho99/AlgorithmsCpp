#include "OneLinkedList.h"
#include "BinaryTree.h"
#include <iostream>



int main() {
    
    BinNode b(1);
    BinaryTree<int> bb;
    bb.insert(5);
    bb.insert(1);
    bb.insert(2);
    bb.insert(3);
    bb.preorder();


    return 0;
}

//g++ -std=c++17 -Iinclude -o program src/main.cpp 