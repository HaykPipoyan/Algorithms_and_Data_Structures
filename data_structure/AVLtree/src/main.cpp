#include "../headers/AVL.h"
#include <iostream>

int main() {
    AVLtree<int> avlTree;

    avlTree.insert(10);
    avlTree.insert(9);  
    avlTree.preorder();
    std::cout << std::endl;
    avlTree.insert(8);
    avlTree.preorder();
    std::cout << std::endl;
    avlTree.insert(15);
    avlTree.preorder();
    std::cout << std::endl;
    avlTree.insert(16);
    avlTree.preorder();
    std::cout << std::endl;
    avlTree.remove(8);
    avlTree.preorder();
    std::cout << std::endl;

    avlTree.insert(35);
    avlTree.insert(50);

    std::cout << "In-order traversal of AVL tree: ";
    avlTree.inOrderTraversal();
    std::cout << std::endl;
    std::cout << avlTree.search(9)->m_value << std::endl;




    return 0;
}

