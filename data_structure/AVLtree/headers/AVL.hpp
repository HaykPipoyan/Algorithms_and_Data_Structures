#ifndef AVL_HPP
#define AVL_HPP

#include "AVL.h"
#include <stack>
#include <iostream>

template <typename T>
TreeNode<T>::TreeNode(T val)
		: m_left (nullptr)
		, m_right (nullptr)
		, m_value (val)
		, m_height (1)
{}


template <typename T>
AVLtree<T>::AVLtree()
    : m_root(nullptr)
{}

template <typename T>
void AVLtree<T>::insert(T value) 
{
    m_root = insert(m_root, value);
}

template <typename T>
TreeNode<T>* AVLtree<T>::insert(TreeNode<T>* node,  T value) 
{
    if(node == nullptr) {
        return new TreeNode<T>(value);
    }
    if(value > node->m_value) {
        node->m_right = insert(node->m_right, value);
    } else if (value < node->m_value) {
        node->m_left = insert(node->m_left, value);
    } else {
        return node;
    }
    node->m_height = std::max(getHeight(node->m_left), getHeight(node->m_right)) + 1;

    int balance = getBalance(node);
    if(balance > 1 && value < node->m_left->m_value) {
        return rotateRight(node);
    }
    if(balance < -1 && value > node->m_right->m_value) {
        return rotateLeft(node);
    }
    if(balance > 1 && value > node->m_left->m_value) {
        node->m_left = rotateLeft(node->m_left);
        return rotateRight(node);
    }
    if(balance < -1 && value < node->m_right->m_value) {
        node->m_right = rotateRight(node->m_right);
        return rotateLeft(node);
    }
    return node;
}

template <typename T>
void AVLtree<T>::remove(T value)
{
    m_root = remove(m_root, value);
}

template <typename T>
TreeNode<T>* AVLtree<T>::remove(TreeNode<T>* node, T value)
{
    if( node == nullptr) {
        return node;
    }
    if(value > node->m_value) {
        node->m_right = remove(node->m_right, value);
    } else if (value < node->m_value) {
        node->m_left = remove(node->m_left, value);
    } else {
        if(node->m_left == nullptr) {
            TreeNode<T>* tmp = node->m_right;
            delete node;
            return tmp;
        } else if(node->m_right == nullptr) {
            TreeNode<T>* tmp = node->m_left;
            delete node;
            return tmp;
        } else {
            TreeNode<T>* successor = minValueNode(node->m_right);
            node->m_value = successor->m_value;
            node->m_right = remove(node->m_right, successor->m_value);
        }
    }
    if(node != nullptr) {
        int balanceFactor = getBalance(node);
        if(balanceFactor > 1 && getBalance(node->m_left) >= 0) {
            return rotateRight(node);
        } 
        if (balanceFactor > 1 && getBalance(node->m_left) < 0) {
            node->m_left = rotateLeft(node->m_left);
            return rotateRight(node);
        } 
        if(balanceFactor < -1 && getBalance(node->m_right) <= 0) {
            return rotateLeft(node);
        }
        if(balanceFactor < -1 && getBalance(node->m_right) > 0) {
            node->m_right = rotateRight(node->m_right);
            return rotateLeft(node);
        } 
    }
    return node;
}

template <typename T>
TreeNode<T>* AVLtree<T>::minValueNode(TreeNode<T>* node)
{
    TreeNode<T>* current = node;
    while(current && current->m_left != nullptr) {
        current = current->m_left;
    }
    return current;
}

template <typename T>
TreeNode<T>* AVLtree<T>::search(T value) 
{
    TreeNode<T>* tmp =  search(m_root, value);
    if(tmp) {
        return tmp;
    }
    throw std::logic_error("node with that value not exist");
}

template <typename T>
TreeNode<T>* AVLtree<T>::search(TreeNode<T>* node, T value)
{
    if(node == nullptr) {
        return node;
    }
    if(value < node->m_value) 
    {
        return search(node->m_left, value);
    } 
    else if(value > node->m_value) 
    {
        return search(node->m_right, value);
    } 
    else 
    {
        return node;
    }
}

template <typename T>
void  AVLtree<T>::inOrderTraversal() const 
{
    inOrderTraversal(m_root);
}

template <typename T>
void AVLtree<T>::inOrderTraversal(TreeNode<T>* node) const
{
    if(node != nullptr) {
        std::stack<TreeNode<T>*> stack;
        TreeNode<T>* current = node;
        while(current != nullptr || !stack.empty()){
            while(current != nullptr) {
                stack.push(current);
                current = current->m_left;
            }
            current = stack.top();
            stack.pop();
            std::cout << current->m_value << " ";
            current = current->m_right;
        }
    }
}

template <typename T>
int  AVLtree<T>::getBalance(TreeNode<T>* node)
{
    return node ? getHeight(node->m_left) - getHeight(node->m_right) : 0;
}

template <typename T>
int AVLtree<T>::getHeight(TreeNode<T>* node)
{
    return node == nullptr ? 0 : node->m_height;
}

template <typename T>
TreeNode<T>* AVLtree<T>::rotateLeft(TreeNode<T>* node)
{
    TreeNode<T>* y = node->m_right;
    TreeNode<T>* tmp = y->m_left;
    y->m_left = node;
    node->m_right = tmp;
    node->m_height = std::max(getHeight(node->m_left), getHeight(node->m_right)) + 1;
    y->m_height = std::max(getHeight(y->m_left), getHeight(y->m_right)) + 1;
    return y;
} 

template <typename T>
TreeNode<T>* AVLtree<T>::rotateRight(TreeNode<T>* node)
{
    TreeNode<T>* x = node->m_left;
    TreeNode<T>* tmp = x->m_right;
    x->m_right = node;
    node->m_left = tmp;
    node->m_height = std::max(getHeight(node->m_left), getHeight(node->m_right)) + 1;
    x->m_height = std::max(getHeight(x->m_left), getHeight(x->m_right)) + 1;
    return x;
}

template <typename T>
void AVLtree<T>::preorder() 
{
    preorder(m_root);
}

template <typename T>
void AVLtree<T>::preorder(TreeNode<T>* node)
{
    if(node == nullptr) {
        return;
    }
    std::cout << node->m_value;
    preorder(node->m_left);
    preorder(node->m_right);
}




#endif // AVL_HPP