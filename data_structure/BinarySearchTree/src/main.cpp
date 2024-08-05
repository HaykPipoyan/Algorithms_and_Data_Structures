#include <iostream>
#include "../headers/BinarySearchTree.hpp"


int main() {
    BST<int> bst;
    bst.add(5);
    bst.add(3);
    bst.add(7);
    bst.add(2);
    bst.add(4);
    bst.add(6);
    bst.add(8);
    std::cout << "Is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Number of nodes: " << bst.getNumberOfNodes() << std::endl;
    std::cout << "Height of the tree: " << bst.getHeight() << std::endl;
    int searchValue = 4;
    std::cout << "Does the tree contain " << searchValue << "? " 
              << (bst.contains(searchValue) ? "Yes" : "No") << std::endl;
    int rootData = bst.getRootData();
    std::cout << "Root data: " << rootData << std::endl;
    bst.setRootData(10);
    std::cout << "New root data: " << bst.getRootData() << std::endl;
    
    std::cout << "Preorder traversal: ";
    bst.preorderTraverse();
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    bst.inorderTraverse();
    std::cout << std::endl;
    bst.levelorderTraverse();
    bst.remove(4);
    bst.levelorderTraverse();
    bst.clear();
    std::cout << "Tree cleared." << std::endl;

    std::cout << "Is the tree empty now? " << (bst.isEmpty() ? "Yes" : "No") << std::endl;
    bst.postorderTraverse();
    
    
}
