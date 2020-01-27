#include "./include/bst.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>

int
main(void)
{
    bst<int> tree;
    srand(time(NULL));

    for (int i = 0; i < 20; ++i) {
        tree.insert(rand()%100 + 1);
    }

    std::cout << tree << std::endl;

    int torem;
    std::cin >> torem;
    tree.remove(torem);
    std::cout << tree << std::endl;
    return 0;   
}