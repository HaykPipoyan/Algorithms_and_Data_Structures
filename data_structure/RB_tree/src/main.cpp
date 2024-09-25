#include "../headers/RBtree.h"

#include <iostream>

int main() {
    RBtree<int> RB;
    RB.insert(22);
    RB.insert(11);
    RB.insert(44);
    RB.insert(55);
    RB.insert(33);
    RB.insert(9);
    RB.insert(12);

    RB.preOrederTraversal();
    RB.inOrderTraversal();
    RB.postOrederTraversal();
    RB.levelOrderTraversal();
    RB.remove(11);
    RB.postOrederTraversal();
}