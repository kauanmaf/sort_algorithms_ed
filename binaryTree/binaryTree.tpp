#include <iostream>

#include "binaryTree.h"
#include "../list/list.h"

using namespace std;

template <typename T>
NodeTree<T>* newNodeTree(T data)
{
    NodeTree<T>* tmp = (NodeTree<T>*) malloc(sizeof(NodeTree<T>));
    if (tmp == nullptr)
    {
        cerr << "Erro em newNodeTree: malloc" << endl;
        exit(1);
    }
    
    tmp -> payload = data;
    tmp -> ptrLeft = nullptr;
    tmp -> ptrRight = nullptr;
    return tmp;
};

// Passa a raiz e retorna a raiz com o nó inserido
template <typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>* startingNodeTree, T data)
{
    // Checando se é a lista é nula
    if (startingNodeTree == nullptr) return newNodeTree(data);

    // Checando se o valor é menor que o valor é menos que o payload
    if (data < startingNodeTree -> payload) startingNodeTree -> ptrLeft = insertNodeTree(startingNodeTree -> ptrLeft, data);

    // Se for maior, inserimos na direita
    else startingNodeTree -> ptrRight = insertNodeTree(startingNodeTree -> ptrRight, data);

    return startingNodeTree;

}

template <typename T>
void bfsTraversal(NodeTree<T>* startingNodeTree)
{
    // # Vetor
    if (startingNodeTree == nullptr) return;

    // Criando a lista 
    Node<NodeTree<T>*>* head = nullptr; 

    Node<NodeTree<T>*>* current = nullptr;

    insertEnd(&head, startingNodeTree);

    current = head;

    while (current != nullptr)
    {

        cout << current -> payload -> payload << " ";

        if (current -> payload -> ptrLeft != nullptr)
        {
            insertEnd(&head, current -> payload -> ptrLeft);
        }
        if (current -> payload -> ptrRight != nullptr)
        {
            insertEnd(&head, current -> payload -> ptrRight);
        }

        current = current -> ptrNext;
        
    }
    cout << endl;
}

template <typename T>
NodeTree<T>* searchBfs(NodeTree<T>* startingNodeTree, T data)
{
    // # Vetor
    if (startingNodeTree == nullptr) return nullptr;

    // Criando a lista 
    Node<NodeTree<T>*>* head = nullptr; 

    Node<NodeTree<T>*>* current = nullptr;

    insertEnd(&head, startingNodeTree);

    current = head;

    while (current != nullptr)
    {
        if (current -> payload -> payload == data)
        {
            return current -> payload;
        }

        if (current -> payload -> ptrLeft != nullptr)
        {
            insertEnd(&head, current -> payload -> ptrLeft);
        }
        if (current -> payload -> ptrRight != nullptr)
        {
            insertEnd(&head, current -> payload -> ptrRight);
        }

        current = current -> ptrNext;
        
    }
    cout << "Nó não encontrado" << endl;
    return nullptr;
}

template <typename T>
void cleanTree(NodeTree<T>* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        cleanTree(ptrStartingNode -> ptrLeft);
        cleanTree(ptrStartingNode -> ptrRight);
        free(ptrStartingNode);
    }
}

template <typename T>
NodeTree<T>* lesserLeaf(NodeTree<T>* ptrStartingNode)
{
    NodeTree<T>* ptrCurrent = ptrStartingNode;
    
    while (ptrCurrent && ptrCurrent -> ptrLeft != nullptr)
    {
        ptrCurrent = ptrCurrent -> ptrLeft;
    }
    
    return ptrCurrent;
}

template <typename T>
NodeTree<T>* deleteNode(NodeTree<T>* ptrStartingNode, T data)
{
    if (ptrStartingNode == nullptr)
    {
        cout << "Elemento não encontrado" << endl;
        return nullptr;
    }
    
    if (data < ptrStartingNode -> payload)
    {
        ptrStartingNode -> ptrLeft = deleteNode(ptrStartingNode -> ptrLeft, data);
    }
    else if (data > ptrStartingNode -> payload)
    {
        ptrStartingNode -> ptrRight = deleteNode(ptrStartingNode -> ptrRight, data);
    }
    else
    {
        NodeTree<T>* ptrTemp = nullptr;
        
        if (ptrStartingNode -> ptrLeft == nullptr)
        {
            ptrTemp = ptrStartingNode -> ptrRight;
            free(ptrStartingNode);
            return ptrTemp;
        }
        else if (ptrStartingNode -> ptrRight == nullptr)
        {
            ptrTemp = ptrStartingNode -> ptrLeft;
            free(ptrStartingNode);
            return ptrTemp;
        }
        
        ptrTemp = lesserLeaf(ptrStartingNode -> ptrRight);
        
        ptrStartingNode -> payload = ptrTemp -> payload;
        
        ptrStartingNode -> ptrRight = deleteNode(ptrStartingNode -> ptrRight, ptrTemp -> payload);
    }
    
    return ptrStartingNode;
}


template <typename T>
NodeTree<T>* dfsTraversal(NodeTree<T>* ptrStartingNodeTree, T data)
{
    // if (ptrStartingNodeTree == nullptr) return nullptr;
    // if (ptrStartingNodeTree -> payload == data) return ptrStartingNodeTree ;
    // else if (data < ptrStartingNodeTree -> payload) return dfsTraversal(ptrStartingNodeTree -> ptrLeft, data);
    // else return dfsTraversal(ptrStartingNodeTree -> ptrRight, data);
    if (ptrStartingNodeTree == nullptr) return nullptr;

    if (ptrStartingNodeTree->payload == data) return ptrStartingNodeTree;

    NodeTree<T>* leftResult = dfsTraversal(ptrStartingNodeTree->ptrLeft, data);
    if (leftResult != nullptr) return leftResult;
    
    return dfsTraversal(ptrStartingNodeTree->ptrRight, data);
}



