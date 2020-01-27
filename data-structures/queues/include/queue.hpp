#pragma once

#include "../../Lists/include/linked_list.hpp"

#ifndef _QUEUE_H_
#define _QUEUE_H_

TEMPLATE_T
class queue : public linkedlist<T>
{
public:
    queue();
    ~queue();
    
    void push(T el);
    void pop();
    T top();
};

TEMPLATE_T
queue<T>::queue() {}

TEMPLATE_T
queue<T>::~queue() {}

TEMPLATE_T
void 
queue<T>::push(T el)
{
    this->add_back(el);
}

TEMPLATE_T
void
queue<T>::pop()
{
    this->remove(0);
}

TEMPLATE_T
T
queue<T>::top()
{
    return this->head_->data;
}

#endif /* _QUEUE_H_ */