#pragma once
// Definição da estrutura Node
struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};

// Protótipos das funções
Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);
void removeList(Node**);
void swapElements(Node*, Node*);