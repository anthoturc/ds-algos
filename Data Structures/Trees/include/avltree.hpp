/*
 *  Implementation of an AVL tree for generic data types.
 *  Note that these data types must be comparable and that 
 *  the balance factor for each node in the tree is computed as 
 *  (right subtree height) - (left subtree height)
 */ 

#pragma once

#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include <cstddef>
#include <iostream>

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

    bool isBalanced();

    template<typename TT>
    friend std::ostream& operator<<(std::ostream& os, const avltree<TT>& other);

private:
    struct avlnode
    {
        T data;
        avlnode * left;
        avlnode * right;
        int height;
        int balanceFactor;
    };

    avlnode * root_;
    std::size_t size_;

    avlnode * initNode(T el);
    
    /* recursive helper methods */
    avlnode * auxInsert(avlnode * node, T el);
    avlnode * auxRemove(avlnode * node, T el);
    avlnode * auxContains(avlnode * node, T el);

    /* basic rotations */
    avlnode * rightrotation(avlnode * node);
    avlnode * leftrotation(avlnode * node);

    /* rotations for different cases */
    avlnode * leftLeft(avlnode * node);
    avlnode * leftRight(avlnode * node);
    avlnode * rightRight(avlnode * node);
    avlnode * rightLeft(avlnode * node);

    /* height method that handles null nodes */
    int height(avlnode * node);
    void updateNode(avlnode * node);

    /* balance method */
    avlnode * balance(avlnode * node);
    bool isBalancedAux(avlnode * node, int& depth);

    /* recursive print */
    void printTree(std::ostream& os, avlnode * node, std::size_t spaces) const;
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
int
avltree<T>::height(avlnode * node) 
{
    if (!node) return -1;
    return node->height;
}

TEMPLATE_T
typename avltree<T>::avlnode * 
avltree<T>::leftLeft(avlnode * node)
{
    return rightrotation(node);
}

TEMPLATE_T
typename avltree<T>::avlnode * 
avltree<T>::leftRight(avlnode * node)
{
    node->left = leftrotation(node->left);
    return rightrotation(node);
}

TEMPLATE_T
typename avltree<T>::avlnode * 
avltree<T>::rightRight(avlnode * node)
{
    return leftrotation(node);
}

TEMPLATE_T
typename avltree<T>::avlnode * 
avltree<T>::rightLeft(avlnode * node)
{
    node->right = rightrotation(node->right);
    return leftrotation(node);
}

TEMPLATE_T
typename avltree<T>::avlnode *
avltree<T>::balance(avlnode * node)
{
    if (node->balanceFactor < -1) { // subtree is left heavy
        if (node->left->balanceFactor <= 0) { // left child is bigger on left side
            return leftLeft(node);
        } else { // left child is bigger on the right side
            return leftRight(node);
        }
    } else if (node->balanceFactor > 1) { // subtree is right heavy
        if (node->right->balanceFactor >= 0) { // right child is bigger on the right side
            return rightRight(node);
        } else { // right child is bigger on the left side
            return rightLeft(node);
        }
    }

    return node; // node is balanced
}

TEMPLATE_T
typename avltree<T>::avlnode * 
avltree<T>::rightrotation(avlnode * node)
{
    avlnode * newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    updateNode(node);
    updateNode(newRoot);

    return newRoot;
}

TEMPLATE_T
typename avltree<T>::avlnode * 
avltree<T>::leftrotation(avlnode * node)
{
    avlnode * newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    updateNode(node);
    updateNode(newRoot);

    return newRoot;
}


TEMPLATE_T
typename avltree<T>::avlnode *
avltree<T>::initNode(T el)
{
    avlnode * node = new avlnode;
    node->data = el;
    node->left = node->right = nullptr;
    node->height = 0;
    node->balanceFactor = 0;
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
void
avltree<T>::updateNode(avlnode * node)
{
    int rightH = height(node->right);
    int leftH = height(node->left);

    node->height = std::max(rightH, leftH) + 1;

    node->balanceFactor = (int)rightH - (int)leftH;
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
    } else { // no duplicates allowed (-:
        return node;
    }

    updateNode(node);

    return balance(node);
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
        if (!(node->left)) {
            tmp = node->right;
            delete node;
            return tmp;
        } else if (!(node->right)) {
            tmp = node->left;
            delete node;
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
    
    // update this node 
    updateNode(node);

    return balance(node);
}

TEMPLATE_T
std::ostream&
operator<<(std::ostream& os, const avltree<T>& other)
{
    other.printTree(os, other.root_, 0);
    return os;
}

TEMPLATE_T
void
avltree<T>::printTree(std::ostream& os, avlnode * node, std::size_t spaces) const
{
    if (!node) return;
    printTree(os, node->right, spaces + 10);
    for (std::size_t i = 0; i < spaces; ++i) {
        os << " ";
    }
    os << node->data << std::endl;
    printTree(os, node->left, spaces + 10);
}

TEMPLATE_T
bool
avltree<T>::isBalanced()
{
    int leaf = 0;
    return isBalancedAux(root_, leaf);
}

TEMPLATE_T
bool
avltree<T>::isBalancedAux(avlnode * node, int& depth) 
{
    if (!node) {
        depth = 0;
        return true;
    }
    
    if (!(node->left) && !(node->right)) {
        depth = 0;
        return true;
    }

    int leftHeight = isBalancedAux(node->left, depth);
    int rightHeight = isBalancedAux(node->right, depth);

    depth = std::max(rightHeight, leftHeight) + 1;
    if (std::abs(rightHeight-leftHeight) > 1) return false;
    return true;
}

#endif /* _AVL_TREE_H_ */