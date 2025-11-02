#include "OneLinkedList.h"
#include "BinaryTree.h"
#include <iostream>



int main() {
    
    BinNode b(1);
    BinaryTree<int> bb;

    std::cout << bb.is_empty() << std::endl;

    return 0;
}

//g++ -std=c++17 -Iinclude -o program src/main.cpp 