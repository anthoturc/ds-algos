#include "include/linked_list.hpp"
#include <string>
#include <iostream>

int
main(void)
{
    linkedlist<int> l;
    for (int i = 0; i < 10; ++i) {
        l.add_back(i);
    }

    std::cout << l << std::endl;

    for (int i = -10; i < 0; ++i) {
        l.add_front(i);  
    }
    std::cout << l << std::endl;

    l.remove(0);
    std::cout << l << std::endl;
    
    l.remove(0);
    std::cout << l << std::endl;

    l.remove(8);
    std::cout << l << std::endl;

    std::cout << l.size() << std::endl;
    return 0;  
}
