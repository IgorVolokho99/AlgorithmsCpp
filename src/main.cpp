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
    bb.insert(6);
     bb.insert(6);
      bb.insert(6);
       bb.insert(6);
       bb.insert(6);
    bb.level_order();
    std::cout << bb.height() << std::endl;


    //          5
    //       1      2
    //     3   6

    return 0;
}

//g++ -std=c++17 -Iinclude -o program src/main.cpp 