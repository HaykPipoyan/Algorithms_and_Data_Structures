#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template<typename T>
class TreeNode {
    public:
        TreeNode(T newData = 0);

        TreeNode* m_left;
        TreeNode* m_right;
        T m_data;
};

template<typename T>
class BST {
    public:
        BST();
        ~BST();

        bool isEmpty(); // Method to check if the tree is empty
        int getHeight(); // Method to get the height of the tree
        int getNumberOfNodes(); // Method to get the number of nodes in the tree
        const T& getRootData() const; // Method to get the data of the root node
        void setRootData(T newData); // Method to set the data of the root node
        bool add(T newData); // Method to add a new node with the given data
        void clear(); // Method to remove all nodes from the tree
        T getEntry(T anEntry); // Method to find an entry in the tree
        bool contains(T data) const; // Method to check if the tree contains a given data
        void preorderTraverse() const; // Method to traverse the tree in pre-order
        void inorderTraverse() const; // Method to traverse the tree in in-order
    
    private:
        int getHeight(TreeNode<T>* node);
        void clear(TreeNode<T>* node);
        int getNumberOfNodes(TreeNode<T>* node);
        bool add(TreeNode<T>*& node, T newData);
        TreeNode<T>* getEntry(TreeNode<T>* node, T anEntry) const;
        bool contains(TreeNode<T>* node, T data) const;
        void preorderTraverse(TreeNode<T>* node) const;
        void inorderTraverse(TreeNode<T>* node) const;

    private:
        TreeNode<T>* m_root;

};

#include "BinarySearchTree.hpp"

#endif // BINARYSEARCHTREE_H