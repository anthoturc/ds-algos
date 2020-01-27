#pragma once

#include "../../Lists/include/linked_list.hpp"

#ifndef _STACK_H_
#define _STACK_H_

TEMPLATE_T
class stack : public linkedlist<T>
{
public:
    stack();
    ~stack();
    void push(T el);
    void pop();
    T top();
};

TEMPLATE_T
stack<T>::stack() {}

TEMPLATE_T
stack<T>::~stack() {}

TEMPLATE_T
void
stack<T>::push(T el)
{
    this->add_front(el);
}

TEMPLATE_T
void 
stack<T>::pop()
{
    this->remove(0);
}

TEMPLATE_T
T
stack<T>::top()
{
    return this->head_->data;
}

#endif /* _STACK_H_ */