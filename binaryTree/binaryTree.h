#pragma once

// Estrutura do nó da árvore
template <typename T>
struct NodeTree
{
    T payload;
    NodeTree* ptrLeft;
    NodeTree* ptrRight;

};

// Protótipos
template <typename T>
NodeTree<T>* newNodeTree(T);

template <typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>*, T);

template <typename T>
void cleanTree(NodeTree<T>*);

template <typename T>
NodeTree<T>* lesserLeaf(NodeTree<T>*);

template <typename T>
void bfsTraversal(NodeTree<T>*);

template <typename T>
NodeTree<T>* searchBfs(NodeTree<T>*, T);

template <typename T>
NodeTree<T>* dfsTraversal(NodeTree<T>*, T);


#include "binaryTree.tpp"