#ifndef RBTREE_H
#define RBTREE_H

#include<iostream>

enum Color {
    Red,
    Black
};

template <typename T>
class TreeNode {
public:   
    T m_key;
    TreeNode* m_left;
    TreeNode* m_right;
    TreeNode* m_parent;
    Color m_color;
    TreeNode(T key);
};

template <typename T>
class RBtree {
public:
    RBtree();
    ~RBtree();
    
    void insert(T key);
    const TreeNode<T>* find(T val) const; 
    void remove(T val);
    void preOrederTraversal() const;
    void inOrderTraversal() const; 
    void postOrederTraversal() const;
    void levelOrderTraversal() const;

private:
    void remove(TreeNode<T>* current, T val); 
    TreeNode<T>* leftRotate(TreeNode<T>* current);
    TreeNode<T>* rightRotate(TreeNode<T>* current);
    void insertFixUp(TreeNode<T>* newNode);
    TreeNode<T>* find(TreeNode<T>* current, T val) const; 
    void deleteFixUp(TreeNode<T>* current);
    void transplant(TreeNode<T>* target, TreeNode<T>* with);
    TreeNode<T>* treeMinimum(TreeNode<T>* current) const;
    void clear(TreeNode<T>* current);
    void inOrderTraversal(TreeNode<T>* current) const;
    void preOrederTraversal(TreeNode<T>* current) const;
    void postOrederTraversal(TreeNode<T>* current) const;
    void levelOrderTraversal(TreeNode<T>* current) const;


    TreeNode<T>* m_root;
    TreeNode<T>* m_nil;

};

#include "RBtree.hpp"

#endif // RBTREE_H