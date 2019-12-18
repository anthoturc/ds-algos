#pragma once

#include <cstddef>
#include <iostream>

#ifndef _BST_H_
#define _BST_H_

#define TEMPLATE_T template<typename T>
#define NSPACES 10

TEMPLATE_T
class bst
{
public:
    bst();
    ~bst();

    void insert(T el);
    bool contains(T el);
    void remove(T el);
    std::size_t size();

    template<typename TT>
    friend std::ostream& operator<<(std::ostream& os, const bst<TT>& tree);

private:
    struct bstnode
    {
        T data;
        bstnode * left;
        bstnode * right;
    };

    std::size_t size_;
    bstnode * root_;

    bstnode * initNode(T el);

    bstnode * auxInsert(bstnode * node, T el);
    bstnode * auxRemove(bstnode * node, T el);
    bstnode * find(bstnode * node, T el);

    void inOrder(std::ostream& os, bstnode * node, std::size_t tabs) const;
};

TEMPLATE_T
bst<T>::bst() : size_(0), root_(nullptr) {}

TEMPLATE_T
bst<T>::~bst() {}

TEMPLATE_T
typename bst<T>::bstnode *
bst<T>::initNode(T el)
{
    bstnode * newNode = new bstnode;
    newNode->data = el;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

TEMPLATE_T
void
bst<T>::insert(T el)
{
    root_ = auxInsert(root_, el);
    ++size_;
}

TEMPLATE_T 
typename bst<T>::bstnode *
bst<T>::auxInsert(bstnode * node, T el)
{
    if (!node) return initNode(el);

    if (node->data < el) {
        node->right = auxInsert(node->right, el);
    } else {
        node->left = auxInsert(node->left, el);
    }

    return node;
}

TEMPLATE_T
bool 
bst<T>::contains(T el)
{
    return find(root_, el) != nullptr;
}

TEMPLATE_T
typename bst<T>::bstnode *
bst<T>::find(bstnode * node, T el)
{
    if (!node) return node;

    if (node->data == el) return node;

    if (node->data < el) {
        return find(node->right, el);
    }
    return find(node->left, el);
}

TEMPLATE_T
void
bst<T>::remove(T el)
{
    root_ = auxRemove(root_, el);
    --size_;
}

TEMPLATE_T
typename bst<T>::bstnode * 
bst<T>::auxRemove(bstnode * node, T el)
{
    if (!node) return node;
    
    if (node->data < el) {
        node->right = auxRemove(node->right, el);
    } else if (node->data > el) {
        node->left = auxRemove(node->left, el);
    } else {
        bstnode * tmp;
        if (!(node->left) && !(node->right)) {
            delete node;
            return nullptr;
        } else if (node->left && !(node->right)) {
            tmp = node->left;
            delete node;
            return tmp;
        } else if (node->right && !(node->left)) {
            tmp = node->right;
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

    return node;
}

TEMPLATE_T
std::ostream&
operator<<(std::ostream& os, const bst<T>& tree)
{
    tree.inOrder(os, tree.root_, 0);
    return os;
}

TEMPLATE_T
void 
bst<T>::inOrder(std::ostream& os, bstnode * node, std::size_t spaces) const
{
    if (!node) return;
    spaces += NSPACES;
    inOrder(os, node->right, spaces);
    for (std::size_t i = 0; i < spaces; ++i) {
        os << " ";
    }
    os << node->data << std::endl;
    inOrder(os, node->left, spaces);
    os << std::endl;
}

TEMPLATE_T
std::size_t 
bst<T>::size()
{
    return size_;
}

#endif /* _BST_H_ */