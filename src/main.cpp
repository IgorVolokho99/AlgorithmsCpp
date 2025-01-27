#include "OneLinkedList.h"
#include <iostream>


int main() {
    
    OneLinkedList<int> oll;


    oll.push_back(1);
    oll.push_back(2);
    oll.push_back(3);


    std::cout << oll.pop_front() <<std::endl;
    std::cout << oll.pop_back() <<std::endl;


    std::cout << oll.head->value << std::endl;
    std::cout << oll.tail->value << std::endl;
    std::cout << oll.pop_back() <<std::endl;


    return 0;
}

//g++ -std=c++17 -Iinclude -o program src/main.cpp 