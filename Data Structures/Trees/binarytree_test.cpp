#include "./include/binarytree.hpp"
#include <iostream>

int
main(void)
{
    binarytree<int> tree; 
    for (int i = 0; i < 8; ++i) {
        tree.insert(i);
    }

    if (tree.contains(3)) {
        std::cout << "there is 3" << std::endl; 
    }
    std::cout << tree << std::endl; 
    std::cout << "---------------------------------------------" << std::endl;
    tree.remove(3);
    std::cout << tree << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    tree.remove(0);
    std::cout << tree << std::endl;
    return 0;  
}