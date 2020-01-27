/*
 *  Implementation of a singly linked list 
 */ 

#pragma once 

#include <cstddef>
#include <iostream>

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#define TEMPLATE_T template<typename T>

TEMPLATE_T
class linkedlist
{
public:
    linkedlist();
    ~linkedlist();

    void add_front(T el);
    void add_back(T el);
    bool remove(std::size_t idx);

    template<typename TT>
    friend std::ostream& operator<<(std::ostream& os, const linkedlist<TT>& l);

    std::size_t size();

protected:
    struct listnode 
    {
        T data;
        listnode * next;
        listnode * prev; 
    };

    listnode * head_;
    listnode * tail_;
    std::size_t size_;
};

TEMPLATE_T
linkedlist<T>::linkedlist()
{
    size_ = 0;
    head_ = tail_ = nullptr;
}

TEMPLATE_T
linkedlist<T>::~linkedlist()
{
    listnode * tmp = head_;
    while (tmp->next) {
        tmp = tmp->next;
        delete tmp->prev;
        tmp->prev = nullptr;
    }
    
    if (tmp) {
        delete tmp;
    }

    head_ = tail_ = nullptr;
    size_ = 0;
}

TEMPLATE_T
void 
linkedlist<T>::add_back(T el) 
{
    listnode * node = new listnode;
    node->data = el;
    node->prev = node->next = nullptr;
    if (tail_) {
        tail_->next = node;
        node->prev = tail_;
        tail_ = node;
    } else {
        head_ = tail_ = node;
    }
    ++size_;
}

TEMPLATE_T
void
linkedlist<T>::add_front(T el)
{
    listnode * node = new listnode;
    node->data = el;
    node->prev = node->next = nullptr;
    if (head_) {
        node->next = head_;
        head_->prev = node;
        head_ = node;
    } else {
        head_ = tail_ = node;
    }
    ++size_;
}

TEMPLATE_T
bool
linkedlist<T>::remove(std::size_t idx) 
{
    if (!head_ || idx < 0 || idx >= size_) return false;

    listnode * tmp = head_;
    
    std::size_t i = 0;
    while (i < idx) {
        tmp = tmp->next;
        ++i;
    }
    
    if (tmp == head_) {
        head_ = head_->next;
        if (head_)
            head_->prev = nullptr;
        else 
            tail_ = nullptr;
    } else if (tmp == tail_) { 
        tail_ = tail_->prev;
        if (tail_)
            tail_->next = nullptr;
        else    
            head_ = nullptr;
    } else {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }

    tmp->prev = nullptr;
    tmp->prev = nullptr;
    delete tmp;

    --size_;

    return true;
}

TEMPLATE_T
std::size_t
linkedlist<T>::size()
{
    return size_;
}

TEMPLATE_T
std::ostream& 
operator<<(std::ostream& os, const linkedlist<T>& l)
{
   typename linkedlist<T>::listnode * tmp = l.head_;
    while (tmp) {
        os << tmp->data << " <-> ";
        tmp = tmp->next;
    }
    os << "null" << std::endl;
    return os;
}

#endif /* _LINKED_LIST_H_ */