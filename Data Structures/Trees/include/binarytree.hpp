/*
 *  Implementation of binary tree with
 *  insertion happenning randomly on the left 
 *  or right of each binary node
 */
#pragma once

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <queue>
#include <cstddef>
#include <cstdlib>
#include <time.h>
#include <iostream>

#define TEMPLATE_T template<typename T>

TEMPLATE_T
class binarytree
{
public:
    binarytree();
    ~binarytree();

    void insert(T el);
    bool contains(T el);
    void remove(T el);

    template<typename TT>
    friend std::ostream& operator<<(std::ostream& os, const binarytree<TT>& t);

private:
    struct binarynode
    {
        T data;
        binarytree * left;
        binarynode * right;
    };
    binarynode * root_;
    std::size_t size_;

    binarynode * initNode(T el);
    binarynode * auxInsert(binarynode * node, T el);
    binarynode * auxContains(T el);
    void auxRemove(T el);
};

TEMPLATE_T
binarytree<T>::binarytree()
{
    root_ = nullptr;
    size_ = 0;
    srand(time(NULL));
}

TEMPLATE_T
binarytree<T>::~binarytree() {}

TEMPLATE_T
binarytree<T>::binarynode *
binarytree<T>::initNode(T el)
{
    binarynode * newNode = new binarynode;
    newNode->data = T;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

TEMPLATE_T
void
binarytree<T>::insert(T el)
{
    root_ = auxInsert(root_, el);
}

TEMPLATE_T
binarytree<T>::binarynode * 
binarytree<T>::auxInsert(binarynode * node, T el)
{
    if (!node) return initNode(el);    

    auto randV = rand()%10 + 1;

    if (randV <= 5) {
        node->left = auxInsert(node->left, el);
    } else {
        node->right = auxInsert(node->right, el); 
    }

    return node;
}

TEMPLATE_T
bool
binarytree<T>::contains(T el)
{
    return auxContains(el) != nullptr;
}

TEMPLATE_T
binarytree<T>::binarynode *
binarytree<T>::auxContains(T el)
{
    if (!root_) return nullptr;
    std::queue<binarynode *> q;
    q.push(root_);

    while (!q.empty()) {
        auto sz = q.size();
        for (int i = 0; i < sz; ++i) {
            binarynode * currNode = q.front();
            q.pop();
            if (currNode->data == el) return currNode;
            if (currNode->left) q.push(currNode->left);
            if (currNode->right) q.push(currNode->right);
        }
    }
    return nullptr;
}

TEMPLATE_T
void 
binarytree<T>::remove(T el)
{
    if (!root_) return;
    auxRemove(el);
}

TEMPLATE_T
void 
binarytree<T>::auxRemove(T el)
{
    if (!root_) return nullptr;
    
    binarynode * toRem = auxContains(el);
    if (!toRem) return nullptr;

    binarynode * tmp = root_;
    while (tmp->right) {
        tmp = tmp->right;
    }

    toRem->data = tmp->data;

    if (tmp == root_) {
        root_ = root_->left;
    } else {

        binarynode * newPar = root_;
        while (newPar->right != tmp) {
            newPar = newPar->right;
        }

        newPar->right = tmp->left;
    }

    delete tmp;
}

TEMPLATE_T
std::ostream&
operator<<(std::ostream& os, const binarytree<T>& t)
{
    return os;
}

#endif /* _BINARY_TREE_H_ */