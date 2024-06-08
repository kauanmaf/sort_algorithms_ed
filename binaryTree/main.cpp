#include <chrono>
#include <iomanip>

#include <iostream>
#include "binaryTree.h"
// #include "binaryTree.tpp"

using namespace std;

int main() {
    NodeTree<int>* root = nullptr;

    // Inserting nodes
    root = insertNodeTree(root, 50);
    root = insertNodeTree(root, 30);
    root = insertNodeTree(root, 70);
    root = insertNodeTree(root, 20);
    root = insertNodeTree(root, 40);
    root = insertNodeTree(root, 60);
    root = insertNodeTree(root, 80);

    // Performing BFS Traversal
    cout << "BFS Traversal: ";
    bfsTraversal(root);

    // Searching for a node using DFS Traversal
    int searchValue = 60;
    NodeTree<int>* searchResult = dfsTraversal(root, searchValue);
    if (searchResult != nullptr) {
        cout << "Node with value " << searchValue << " found in the tree." << endl;
    } else {
        cout << "Node with value " << searchValue << " not found in the tree." << endl;
    }

    return 0;
}
