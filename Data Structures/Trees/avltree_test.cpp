#include "./include/avltree.hpp"
#include<iostream>

int  
main(void)
{
    avltree<int> t;
    for (int i = 0; i < 20; ++i) {
        t.insert(i);
        std::cout << t << std::endl; 
        if (!t.isBalanced()) {
            std::cout << "The tree is not balanced" << std::endl;
        }
    } 
    std::cout << t << std::endl;
    std::cout << "*************" << std::endl; 
    for (int i = 20; i >= 0; --i) {  
        t.remove(i);
        if (!t.isBalanced()) {
            std::cout << "The tree is not balanced" << std::endl;
        }
        std::cout << "-----------" << std::endl;
    }
    return 0;
}