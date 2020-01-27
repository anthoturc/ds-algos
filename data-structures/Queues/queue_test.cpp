#include "./include/queue.hpp"

#include <string>

int 
main(void)
{
    queue<std::string> q;
    q.push("anthony");
    q.push("is");
    q.push("the best");
    std::cout << q << std::endl;
    std::cout << q.top() << std::endl;
    q.pop();
    std::cout << q << std::endl;
    q.push("?"); 
    std::cout << q << std::endl; 
    return 0;
}