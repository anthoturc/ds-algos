#pragma once

#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include <cstddef>

#define TEMPLATE_T template<typename T>

TEMPLATE_T
class avltree
{
public:
    avltree();
    ~avltree();

    void insert(T el);
    bool contains(T el);
    void remove(T el);
    std::size_t size();

private:
    struct avlnode
    {
        T data;
        avlnode * left;
        avlnode * right;
        std::size_t balance;
    };

    avlnode * root_;
    std::size_t size_;

    avlnode * initNode(T el);
    
    avlnode * auxInsert(avlnode * node, T el);
    avlnode * auxRemove(avlnode * node, T el);
    avlnode * auxContains(avlnode * node, T el);

    avlnode * rightrotation(avlnode * node);
    avlnode * leftrotation(avlnode * node);
    std::size_t height(avlnode * node);
    
    void balance(avlnode * node);
};

TEMPLATE_T
avltree<T>::avltree()
{
    size_ = 0;
    root_ = nullptr;
}

TEMPLATE_T
avltree<T>::~avltree() {}

TEMPLATE_T
void
avltree<T>::balance(avlnode * node)
{
    int lBal = (node->left) ? node->left->balance : -1;
    int rBal = (node->right) ? node->right->balance : -1;

}

TEMPLATE_T
typename avltree<T>::avlnode *
avltree<T>::initNode(T el)
{
    avlnode * node = new avlnode;
    node->data = el;
    node->left = node->right = nullptr;
    node->balance = 0;
    return node;
}

TEMPLATE_T
void
avltree<T>::insert(T el)
{
    root_ = auxInsert(root_, el);
    ++size_;
}

TEMPLATE_T
typename avltree<T>::avlnode *
avltree<T>::auxInsert(avlnode * node, T el)
{
    if (!node) return initNode(el);

    if (node->data < el) {
        node->right = auxInsert(node->right, el);
    } else if (node->data > el) {
        node->left = auxInsert(node->left, el);
    } else {} // no duplicates allowed (-:

    balance(node);

    return node;
}

TEMPLATE_T
bool
avltree<T>::contains(T el)
{
    return auxContains(root_, el) != nullptr;
}

TEMPLATE_T
typename avltree<T>::avlnode *
avltree<T>::auxContains(avlnode * node, T el)
{
    if (!node) return node;

    if (node->data == el) return node;

    if (node->data < el) {
        return auxContains(node->right, el);
    }
    
    return auxContains(node->left, el);
}

TEMPLATE_T
void
avltree<T>::remove(T el)
{
    root_ = auxRemove(root_, el);
}

TEMPLATE_T
typename avltree<T>::avlnode *
avltree<T>::auxRemove(avlnode * node, T el)
{
    if (!node) return nullptr;

    if (node->data < el) {
        node->right = auxRemove(node->right, el);
    } else if (node->data > el) {
        node->left = auxRemove(node->left, el);
    } else {
        avlnode * tmp;
        if (!(node->left) && !(node->right)) {
            delete node;
            node = nullptr;
            return nullptr;
        } else if (node->left && !(node->right)) {
            tmp = node->left;
            delete node;
            node = nullptr;
            return tmp;
        } else if (node->right && !(node->left)) {
            tmp = node->right;
            delete node;
            node = nullptr;
            return tmp;
        } else {
            tmp = node->left;
            while (tmp->right) {
                tmp = tmp->right;
            }
            node->data = tmp->data;
            node->left = auxRemove(node->left, node->data);
        }
    }

    balance(node);
    return node;
}

#endif /* _AVL_TREE_H_ */