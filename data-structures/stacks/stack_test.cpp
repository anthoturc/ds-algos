#include "./include/stack.hpp"
#include <iostream>

int 
main(void)
{
    stack<char> s;
    s.push(')');
    s.push('(');
    s.push('(');
    s.push('(');
    std::cout << s.size() << std::endl;
    std::cout << s << std::endl;
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s << std::endl;
    return 0;
}