#include "OneLinkedList.h"
#include <iostream>


int main() {
    
    OneLinkedList<int> oll;

    std::cout << oll.is_empty() << std::endl;

    oll.push_back(1);

    std::cout << oll.is_empty() << std::endl;

    std::cout << oll.head->value << std::endl;

    return 0;
}