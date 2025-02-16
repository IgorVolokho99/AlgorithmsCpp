#include "OneLinkedList.h"
#include <iostream>


int main() {
    
    OneLinkedList<int> oll;

    oll.push_back(1);
    oll.push_back(2);
    oll.push_back(3);

    oll.set(2, 10);

    // std::cout << oll.get(-5) << std::endl;
    std::cout << oll.get(2) << std::endl;
    // std::cout << oll.get(2) << std::endl;
    // std::cout << oll.get(3) << std::endl;

    return 0;
}

//g++ -std=c++17 -Iinclude -o program src/main.cpp 