#ifndef RBTREE_HPP
#define RBTREE_HPP
#include "RBtree.h"

#include <iostream>


template <typename T>
TreeNode<T>::TreeNode(T key) 
    : m_key(key)
    , m_left(nullptr)
    , m_right(nullptr)
    , m_parent(nullptr)
    , m_color(Red)
{}

template <typename T>
RBtree<T>::RBtree() 
{
    m_nil = new TreeNode<T>(0);
    m_nil->m_color = Black;
    m_root = m_nil;
}

template <typename T>
RBtree<T>::~RBtree() 
{
    clear(m_root);
    delete m_nil;
}

template <typename T>
void RBtree<T>::clear(TreeNode<T>* current) 
{
    if(current != m_nil) {
        clear(current->m_left);
        clear(current->m_right);
        delete current;
    }
}

template <typename T>
void RBtree<T>::insert(T key)
{
    TreeNode<T>* newNode = new TreeNode<T>(key);
    TreeNode<T>* parentNode = m_nil;
    TreeNode<T>* current = m_root;

    while(current != m_nil) {
        parentNode = current;
        if(newNode->m_key < current->m_key) {
            current = current->m_left;
        } else {
            current = current->m_right;
        }
    }
    newNode->m_parent = parentNode;
    if(parentNode == m_nil) {
        m_root = newNode;
    }
    else if(newNode->m_key < parentNode->m_key) {
        parentNode->m_left = newNode;
    } else {
        parentNode->m_right = newNode;
    }
    newNode->m_left = m_nil;
    newNode->m_right = m_nil;
    newNode->m_color = Red;
    insertFixUp(newNode);
}

template <typename T>
void RBtree<T>::insertFixUp(TreeNode<T>* newNode)
{
    while( newNode->m_parent->m_color == Red) {
        if(newNode->m_parent == newNode->m_parent->m_parent->m_left) {
            TreeNode<T>* uncle = newNode->m_parent->m_parent->m_right;
            if(uncle->m_color == Red) {
                newNode->m_parent->m_color = Black;
                uncle->m_color = Black;
                newNode->m_parent->m_parent->m_color = Red;
                newNode = newNode->m_parent->m_parent;
            } else {
                if(newNode == newNode->m_parent->m_right) {
                    newNode = newNode->m_parent;
                    leftRotate(newNode);
                }
                newNode->m_parent->m_color = Black;
                newNode->m_parent->m_parent->m_color = Red;
                rightRotate(newNode->m_parent->m_parent); 
            }
        } 
        else {
            TreeNode<T>* uncle = newNode->m_parent->m_parent->m_left;
            if (uncle->m_color == Red) {
                newNode->m_parent->m_color = Black;
                uncle->m_color = Black;
                newNode->m_parent->m_parent->m_color = Red;
                newNode = newNode->m_parent->m_parent;
            } else {
                if (newNode == newNode->m_parent->m_left) {
                    newNode = newNode->m_parent;
                    rightRotate(newNode);
                }
                newNode->m_parent->m_color = Black;
                newNode->m_parent->m_parent->m_color = Red;
                leftRotate(newNode->m_parent->m_parent);
            }
        }
    }
    m_root->m_color = Black; 
}

template <typename T>
void RBtree<T>::remove(T val)
{
    remove(m_root, val);
}

template <typename T>
void RBtree<T>::remove(TreeNode<T>* current, T val)
{
    TreeNode<T>* tmp = m_root;
    while(tmp != m_nil)
    {
        if(tmp->m_key > val)
        {
            tmp = tmp->m_left;
        }
        else if(tmp->m_key < val)
        {
            tmp = tmp->m_right;
        }
        else
        {
            break;
        }
    }
       
    TreeNode<T>* del = tmp;
    Color del_color = del->m_color;
    TreeNode<T>* x = m_nil;
    if(del->m_left == m_nil)//Case 1: the node to delete has no left child
    {
        x = del->m_right;
        transplant(del, del->m_right);
    }
    else if(del->m_right == m_nil)//Case 2: the node to delete has no right child
    {
        x = del->m_left;
        transplant(del, del->m_left);
    }
    else//Case 3: the node to delete has both children
    {
        TreeNode<T>* node_to_be_del = treeMinimum(del->m_right);
        del_color = node_to_be_del->m_color;
        x = node_to_be_del->m_right;
        if(node_to_be_del->m_parent == del)
        {
            x->m_parent = node_to_be_del;
        }   
        else 
        {
            transplant(node_to_be_del,node_to_be_del->m_right);
            node_to_be_del->m_right = del->m_right;
            node_to_be_del->m_right->m_parent = node_to_be_del;
        }
            transplant(del,node_to_be_del);
            node_to_be_del->m_left = del->m_left;
            node_to_be_del->m_left->m_parent = node_to_be_del;
            node_to_be_del->m_color = del->m_color;
        }
        if(del_color == Black)
        {
            deleteFixUp(x);
        }
        delete del;
}

template <typename T>
void RBtree<T>::deleteFixUp(TreeNode<T>* current)
{
    while(current != m_root && current->m_color == Black)
    {
        if(current == current->m_parent->m_left)
        {
            TreeNode<T>* sibling = current->m_parent->m_right;
            if(sibling->m_color == Red) // Case 1: x's sibling is red 
            {   
                sibling->m_color = Black;
                current->m_parent->m_color = Red;
                leftRotate(current->m_parent);                    sibling = current->m_parent->m_right;
            }
            if(sibling->m_left->m_color == Black && sibling->m_right->m_color == Black) // Case 2: sibling's children are black
            {
                sibling->m_color = Red;
                current = current->m_parent;
            }
            else
            {
                if(sibling->m_right->m_color == Black) // Case 3 : sibling's right child is black, left child is red
                {
                    sibling->m_left->m_color = Black;
                    sibling->m_color = Red;
                    rightRotate(sibling);
                    sibling = current->m_parent->m_right;
                }
                // Case 4: sibling's right child is red

                sibling->m_color = current->m_parent->m_color;
                current->m_parent->m_color = Black;
                sibling->m_right->m_color = Black;
                leftRotate(current->m_parent);
                current = m_root;
            }
        }
        else// Mirror case
        {
            TreeNode<T>* sibling = current->m_parent->m_left;
            if(sibling->m_color == Red)
            {
                sibling->m_color = Black;
                current->m_parent->m_color = Red;
                rightRotate(current->m_parent);
                sibling = current->m_parent->m_left;
            }
            if(sibling->m_left->m_color == Black && sibling->m_right->m_color == Black)
            {
                sibling->m_color = Red;
                current = current->m_parent;
            }
            else
            {
                if(sibling->m_left->m_color == Black)
                {
                    sibling->m_right->m_color = Black;
                    sibling->m_color = Red;
                    leftRotate(sibling);
                    sibling = current->m_parent->m_left;
                }
                sibling->m_color = current->m_parent->m_color;
                current->m_parent->m_color = Black;
                sibling->m_left->m_color = Black;
                rightRotate(current->m_parent);
                current = m_root;
            }
        }
    }
    current->m_color = Black;
}

template <typename T>
TreeNode<T>* RBtree<T>::leftRotate(TreeNode<T>* current)
{
    TreeNode<T>* tmp = current->m_right;
    current->m_right = tmp->m_left;
    if(tmp->m_left != m_nil) {
        tmp->m_left->m_parent = current;
    }
    tmp->m_parent = current->m_parent;
    if(current->m_parent == m_nil) {
        m_root = tmp;
    }
    else if(current == current->m_parent->m_left) {
        current->m_parent->m_left = tmp;
    } 
    else {
        current->m_parent->m_right = tmp;
    }
    tmp->m_left = current;
    current->m_parent = tmp;
    return tmp;
}

template <typename T>
TreeNode<T>* RBtree<T>::rightRotate(TreeNode<T>* current)
{
    TreeNode<T>* tmp = current->m_left;
    current->m_left = tmp->m_right;
    if(tmp->m_right != m_nil) {
        tmp->m_right->m_parent = current;
    }
    tmp->m_parent = current->m_parent;
    if(current->m_parent == m_nil) {
        m_root = tmp;
    }
    else if(current == current->m_parent->m_left) {
        current->m_parent->m_left = tmp;
    }
    else {
        current->m_parent->m_right = tmp;
    }
    tmp->m_right = current;
    current->m_parent = tmp;
    return tmp;
}

template <typename T>
const TreeNode<T>* RBtree<T>::find(T val) const
{
    return find(m_root, val);
}

template <typename T>
TreeNode<T>* RBtree<T>::find(TreeNode<T>* current, T val) const
{
    if(current == m_nil) {
        return m_nil;
    }
    else if(current->m_key > val) {
        return find(current->m_left, val);
    }
    else if(current->m_key < val) {
        return find(current->m_right, val);
    }
    return current;
}

template <typename T>
void RBtree<T>::preOrederTraversal() const
{
    if(m_root!= m_nil) {
        preOrederTraversal(m_root);
        std::cout << "NIL" << std::endl;
    }
}

template <typename T>
void RBtree<T>::preOrederTraversal(TreeNode<T>* current) const
{
    if(current != m_nil)
    {
        std::cout << current->m_key << " " << current->m_color << "-> ";
        preOrederTraversal (current->m_left);
        preOrederTraversal (current->m_right);
    }
}

//    IN ITERATIVE WAYS

// template <typename T>
// void RBtree<T>::preOrederTraversal(TreeNode<T>* current) const
// {
//     std::stack<TreeNode<T>*> st;
//     st.push(current);
//     while(!st.empty()) {
//         TreeNode<T>* node = st.top();
//         st.pop();
//         std::cout << node->m_key << " " << node->m_color << "->";
//         if(node->m_right != m_nil) {
//             st.push(node->m_right);
//         }
//         if(node->m_left != m_nil) {
//             st.push(node->m_left);
//         }
//     }
// }

template <typename T>
void RBtree<T>::inOrderTraversal() const
{
    inOrderTraversal(m_root);
    std::cout << "NIL" << std::endl;
}

template <typename T>
void RBtree<T>::inOrderTraversal(TreeNode<T>* node) const
{
    if(node != m_nil)
    {
        inOrderTraversal (node->m_left);
        std::cout << node->m_key << " " << node->m_color << " -> ";
        inOrderTraversal (node->m_right);
    }
}

//    IN ITERATIVE WAYS

// template <typename T>
// void RBtree<T>::inOrderTraversal(TreeNode<T>* node) const
// {
//     if(node != nullptr) {
//         std::stack<TreeNode<T>*>stack;
//         TreeNode<T>* current = node;
//         while(current != m_nil || !stack.empty()) {
//             while(current != m_nil) {
//                 stack.push(current);
//                 current = current->m_left;
//             }
//             current = stack.top();
//             stack.pop();
//             std::cout << current->m_key << " ";
//             current = current->m_right;
//         }
//         std::cout << std::endl;
//     }
// }

template <typename T>
void RBtree<T>::postOrederTraversal() const
{
    if(m_root != m_nil) {
        postOrederTraversal(m_root);
        std::cout << "NIL" << std::endl;
    }
}

template <typename T>
void RBtree<T>::postOrederTraversal(TreeNode<T>* current) const
{
    if(current != m_nil) {
        postOrederTraversal(current->m_left);
        postOrederTraversal(current->m_right);
        std::cout << current->m_key << " " << current->m_color << "->";
    }
}

//    IN ITERATIVE WAYS

// template <typename T>
// void RBtree<T>::postOrederTraversal(TreeNode<T>* current) const
// {
//     std::stack<TreeNode<T>*> st;
//     st.push(current);
//     std::stack<T> out;
//     while(!st.empty()) {
//         TreeNode<T>* node = st.top();
//         st.pop();
//         out.push(node->m_key);
//         if(node->m_left != m_nil) {
//             st.push(node->m_left);
//         }
//         if(node->m_right != m_nil) {
//             st.push(node->m_right);
//         }
//     }
//     while(!out.empty()) {
//         std::cout << out.top() << " ";
//         out.pop();
//     }
//     std::cout << std::endl;
// }

template <typename T>
void RBtree<T>::levelOrderTraversal() const
{
    if(m_root != m_nil)
    {
        levelOrderTraversal(m_root);
        std::cout << "NIL" << std::endl;
    }
}

template <typename T>
void RBtree<T>::levelOrderTraversal(TreeNode<T>* current) const
{
    if(current == m_nil) {
        return;
    }
    std::queue<TreeNode<T>*> q;
    q.push(current);
    while(!q.empty()) {
        TreeNode<T>* tmp = q.front();
        q.pop();
        std::cout << tmp->m_key << " " << tmp->m_color << "-> ";
        if(tmp->m_left != m_nil)
        {
            q.push(tmp->m_left);
        }
        if(tmp->m_right != m_nil)
        {
            q.push(tmp->m_right);
        }
    }
}

template <typename T>
void RBtree<T>::transplant(TreeNode<T>* target, TreeNode<T>* with)
{
    if(target->m_parent == m_nil) {
        m_root = with;
    }
    else if (target->m_parent->m_left == target) {
        target->m_parent->m_left = with;
    }
    else {
        target->m_parent->m_right = with;
    }
    with->m_parent = target->m_parent;
}

template <typename T>
TreeNode<T>* RBtree<T>::treeMinimum(TreeNode<T>* current) const
{
    while(current->m_left != m_nil) {
        current = current->m_left;
    }
    return current;
}


#endif // RBTREE_HPP