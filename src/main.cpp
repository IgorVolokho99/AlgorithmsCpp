#include "OneLinkedList.h"
#include <iostream>


int main() {
    
    OneLinkedList<int> oll;

    oll.push_back(1);
    oll.push_back(2);
    oll.push_back(3);


    std::cout << oll.get(0) << std::endl;
    std::cout << oll.get(1) << std::endl;
    std::cout << oll.get(2) << std::endl;

    oll.reverse();

    std::cout << oll.get(0) << std::endl;
    std::cout << oll.get(1) << std::endl;
    std::cout << oll.get(2) << std::endl;

    return 0;
}

//g++ -std=c++17 -Iinclude -o program src/main.cpp 