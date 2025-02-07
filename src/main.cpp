#include "OneLinkedList.h"
#include <iostream>


int main() {
    
    OneLinkedList<int> oll;


    std::cout << oll.get(-5) << std::endl;
    std::cout << oll.get(1) << std::endl;
    std::cout << oll.get(2) << std::endl;
    std::cout << oll.get(3) << std::endl;

    return 0;
}

//g++ -std=c++17 -Iinclude -o program src/main.cpp 