#pragma once

template <typename T>
struct NodeTree
{
    T payload;
    NodeTree* ptrLeft;
    NodeTree* ptrRight;

};

template <typename T>
NodeTree<T>* newNodeTree(T);

template <typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>*, T);

template <typename T>
void bfsTraversal(NodeTree<T>*);

template <typename T>
NodeTree<T>* dfsTraversal(NodeTree<T>*, T);

#include "binaryTree.tpp"
