#include "BinaryTree.h"
#include <iostream>


int main() {
    BinaryTree my_obj;
    my_obj.append(8);
    my_obj.append(2);
    my_obj.append(5);
    my_obj.append(13);
    my_obj.append(1);
    my_obj.append(6);


    Node* b = my_obj.get_head();

    std::cout << b->get_left()->get_right()->get_right()->get_value() << std::endl;


    return 0;
}