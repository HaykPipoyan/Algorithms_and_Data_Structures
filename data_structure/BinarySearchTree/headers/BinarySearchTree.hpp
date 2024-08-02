#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "BinarySearchTree.h"
#include <iostream>
#include <queue>
#include <stack>

template<typename T>
TreeNode<T>::TreeNode(T newData)
    : m_left (nullptr)
    , m_right (nullptr)
    , m_data (newData)
{}

template<typename T>
BST<T>::BST()
    : m_root (nullptr)
{}

template<typename T>
BST<T>::~BST() 
{
    clear();
}

template<typename T>
bool BST<T>::isEmpty()
{
    return m_root == nullptr;;
}

template<typename T>
int BST<T>::getHeight()
{
    if(m_root == nullptr) {
        throw std::out_of_range ("Tree is empty");
    }
    return getHeight(m_root);
}

template<typename T>
int BST<T>::getHeight(TreeNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = getHeight(node->m_left);
    int rightHeight = getHeight(node->m_right);
    return std::max(leftHeight, rightHeight) + 1;
}

//   IN ITERATIVE WAYS

// template<typename T>
// int BST<T>::getHeight()
// {
//     if (m_root == nullptr) {
//         throw std::out_of_range("Tree is empty");
//     }
//     std::queue<TreeNode<T>*> q;
//     q.push(m_root);
//     int height = 0;
//     while (!q.empty()) {
//         int nodeCount = q.size();
//         ++height;
//         while (nodeCount > 0) {
//             TreeNode<T>* current = q.front();
//             q.pop();
//             if (current->m_left != nullptr) {
//                 q.push(current->m_left);
//             }
//             if (current->m_right != nullptr) {
//                 q.push(current->m_right);
//             }
//             --nodeCount;
//         }
//     }
//     return height;
// }

template<typename T>
int BST<T>::getNumberOfNodes() {
    return getNumberOfNodes(m_root);
}

template<typename T>
int BST<T>::getNumberOfNodes(TreeNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + getNumberOfNodes(node->m_left) + getNumberOfNodes(node->m_right);
}

//    IN ITERATIVE WAYS

// template<typename T>
// int BST<T>::getNumberOfNodes() {
//     if (m_root == nullptr) {
//         return 0;
//     }
//     int count = 0;
//     std::queue<TreeNode<T>*> q;
//     q.push(m_root);
//     while (!q.empty()) {
//         TreeNode<T>* current = q.front();  // Получаем указатель на узел, находящийся в начале очереди
//         q.pop();  // Удаляем этот узел из очереди
//         count++;  // Увеличиваем счётчик узлов
//         if (current->m_left != nullptr) {
//             q.push(current->m_left);  // Добавляем левый дочерний узел в очередь
//         }
//         if (current->m_right != nullptr) {
//             q.push(current->m_right);  // Добавляем правый дочерний узел в очередь
//         }
//     }
//     return count;
// }

template<typename T>
const T& BST<T>::getRootData() const {
    if (m_root == nullptr) {
        throw std::out_of_range("Tree is empty");
    }
    return m_root->m_data;
}

template<typename T>
void BST<T>::setRootData(T newData) {
    if (m_root == nullptr) {
        throw std::out_of_range("Tree is empty");
    }
    m_root->m_data = newData;
}

template<typename T>
bool BST<T>::add(T newData) {
    return add(m_root, newData);
}

template<typename T>
bool BST<T>::add(TreeNode<T>*& node, T newData) {
    if (node == nullptr) {
        node = new TreeNode<T>(newData);
        return true;
    }

    if (newData < node->m_data) {
        return add(node->m_left, newData);
    } else if (newData > node->m_data) {
        return add(node->m_right, newData);
    } else {
        return false;
    }
}

//    IN ITERATIVE WAYS

// template<typename T>
// bool BST<T>::add(T newData) {
//     TreeNode<T>* newNode = new TreeNode<T>(newData);    
//     if (m_root == nullptr) {
//         m_root = newNode;
//         return true;
//     }
//     TreeNode<T>* current = m_root;
//     TreeNode<T>* parent = nullptr;
//     while (true) {
//         parent = current;
//         if (newData < current->m_data) {
//             current = current->m_left;
//             if (current == nullptr) {
//                 parent->m_left = newNode;
//                 return true;
//             }
//         } else if (newData > current->m_data) {
//             current = current->m_right;
//             if (current == nullptr) {
//                 parent->m_right = newNode;
//                 return true;
//             }
//         } else {
//             delete newNode;
//             return false;
//         }
//     }
// }

template<typename T>
void BST<T>::clear()
{
    clear(m_root);
    m_root = nullptr;
}

template<typename T>
void BST<T>::clear(TreeNode<T>* node) {
    if (node != nullptr) {
        clear(node->m_left);
        clear(node->m_right);
        delete node;
    }
}

//    IN ITERATIVE WAYS

// template<typename T>
// void BST<T>::clear() {
//     if (m_root == nullptr) {
//         return;
//     }
//     std::stack<TreeNode<T>*> stack;
//     stack.push(m_root);
//     while (!stack.empty()) {
//         TreeNode<T>* node = stack.top();
//         stack.pop();
//         if (node->m_left != nullptr) {
//             stack.push(node->m_left);
//         }
//         if (node->m_right != nullptr) {
//             stack.push(node->m_right);
//         }

//         delete node;
//     }
//     m_root = nullptr;
// }

template<typename T>
T BST<T>::getEntry(T anEntry) {
    TreeNode<T>* node = getEntry(m_root, anEntry);
    if (node == nullptr) {
        throw std::out_of_range("Entry not found in the tree");
    }
    return node->m_data;
}

template<typename T>
TreeNode<T>* BST<T>::getEntry(TreeNode<T>* node, T anEntry) const {
    if (node == nullptr) {
        return nullptr;
    }
    if (anEntry < node->m_data) {
        return getEntry(node->m_left, anEntry);
    } else if (anEntry > node->m_data) {
        return getEntry(node->m_right, anEntry);
    } else {
        return node; 
    }
}

//    IN ITERATIVE WAYS

// template<typename T>
// T BST<T>::getEntry(T anEntry) {
//     TreeNode<T>* node = m_root;
//     while (node != nullptr) {
//         if (anEntry < node->m_data) {
//             node = node->m_left;
//         } else if (anEntry > node->m_data) {
//             node = node->m_right;
//         } else {
//             return node->m_data;
//         }
//     }
//     throw std::out_of_range("Entry not found in the tree");
// }

template<typename T>
bool BST<T>::contains(T data) const {
    return contains(m_root, data);
}

template<typename T>
bool BST<T>::contains(TreeNode<T>* node, T data) const {
    if (node == nullptr) {
        return false;
    }

    if (data < node->m_data) {
        return contains(node->m_left, data);
    } else if (data > node->m_data) {
        return contains(node->m_right, data);
    } else {
        return true;
    }
}

//    IN ITERATIVE WAYS

// template<typename T>
// bool BST<T>::contains(T data) const {
//     TreeNode<T>* node = m_root;
//     while (node != nullptr) {
//         if (data < node->m_data) {
//             node = node->m_left;
//         } else if (data > node->m_data) {
//             node = node->m_right;
//         } else {
//             return true;
//         }
//     }
//     return false;
// }

template<typename T>
void BST<T>::preorderTraverse() const {
    preorderTraverse(m_root);
}

template<typename T>
void BST<T>::preorderTraverse(TreeNode<T>* node) const {
    if (node != nullptr) {
        std::cout << node->m_data << " ";
        preorderTraverse(node->m_left);
        preorderTraverse(node->m_right);
    }
}

//    IN ITERATIVE WAYS

// template<typename T>
// void BST<T>::preorderTraverse() const {
//     if (m_root == nullptr) {
//         return;
//     }
//     std::stack<TreeNode<T>*> st;
//     st.push(m_root);
//     while (!st.empty()) {
//         TreeNode<T>* node = st.top();
//         st.pop();
//         std::cout << node->m_data << " ";
//         if (node->m_right != nullptr) {
//             st.push(node->m_right);
//         }
//         if (node->m_left != nullptr) {
//             st.push(node->m_left);
//         }
//     }
// }


template<typename T>
void BST<T>::inorderTraverse() const {
    inorderTraverse(m_root);
}

template<typename T>
void BST<T>::inorderTraverse(TreeNode<T>* node) const {
    if (node != nullptr) {
        inorderTraverse(node->m_left);
        std::cout << node->m_data << " ";
        inorderTraverse(node->m_right);
    }
}

//    IN ITERATIVE WAYS

// template<typename T>
// void BST<T>::inorderTraverse() const {
//     std::stack<TreeNode<T>*> stack;
//     TreeNode<T>* current = m_root;
//     while (current != nullptr || !stack.empty()) {
//         while (current != nullptr) {
//             stack.push(current);
//             current = current->m_left;
//         }
//         current = stack.top();
//         stack.pop();
//         std::cout << current->m_data << " ";
//         current = current->m_right;
//     }
// }




#endif // BINARYSEARCHTREE_HPP