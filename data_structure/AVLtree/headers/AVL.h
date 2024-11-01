#ifndef AVL_H
#define AVL_H

template <typename T>
class TreeNode {
public:
	TreeNode(T val);
	TreeNode* m_left;
	TreeNode* m_right;
	T m_value;
	int m_height;	
};

template <typename T>
class AVLtree {
public:
	AVLtree();
	void insert(T value);
	void remove(T value); 
	TreeNode<T>* search(T value); 
	int getBalance(TreeNode<T>* node);
	TreeNode<T>* rotateLeft(TreeNode<T>* node); 
	TreeNode<T>* rotateRight(TreeNode<T>* node); 
	int getHeight(TreeNode<T>* node);
	void inOrderTraversal() const; 
	void preorder();
	bool inbalance(TreeNode<T>* root);



private:
	TreeNode<T>* insert(TreeNode<T>* node,  T value);
	TreeNode<T>* remove(TreeNode<T>* node, T value);
	void inOrderTraversal(TreeNode<T>* node) const;
	TreeNode<T>* minValueNode(TreeNode<T>* node);
	void preorder(TreeNode<T>* node);
	TreeNode<T>* search(TreeNode<T>* node ,T value); 

private:
	TreeNode<T>* m_root;	

};

#include "AVL.hpp"

#endif // AVL_H
