#pragma once


// Definição da estrutura Node
template <typename T>
struct Node {
    T payload;
    Node* ptrNext;
    Node* ptrPrev;

};

// Protótipos das funções de lista duplamente encadeada
template <typename T>
Node<T>* createNode(T);

template <typename T>
void insertEnd(Node<T>**, T);

template <typename T>
void displayList(Node<T>*);

template <typename T>
void removeList(Node<T>**);

template <typename T>
void swapElements(Node<T>*, Node<T>*);

#include "double_list.tpp"
