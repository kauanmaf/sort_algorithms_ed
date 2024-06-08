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

    NodeTree<T>* NodeTreeQueue[100];
    int iQueuefront = 0;
    int iQueuerear = 0;

    NodeTreeQueue[iQueuerear] = startingNodeTree;
    iQueuerear++;
    while (iQueuefront != iQueuerear)
    {
        NodeTree<T>* currentNodeTree = NodeTreeQueue[iQueuefront];
        iQueuefront++;

        cout << currentNodeTree -> payload << " ";

        if (currentNodeTree -> ptrLeft != nullptr)
        {
            NodeTreeQueue[iQueuerear] = currentNodeTree -> ptrLeft;
            iQueuerear++;
        }
        if (currentNodeTree -> ptrRight != nullptr)
        {
            NodeTreeQueue[iQueuerear] = currentNodeTree -> ptrRight;
            iQueuerear++;
        }
        
    }
    cout << endl;
}

template <typename T>
NodeTree<T>* dfsTraversal(NodeTree<T>* ptrStartingNodeTree, T data)
{
    if (ptrStartingNodeTree == nullptr) return nullptr;
    if (ptrStartingNodeTree -> payload == data) return ptrStartingNodeTree ;
    else if (data < ptrStartingNodeTree -> payload) return dfsTraversal(ptrStartingNodeTree -> ptrLeft, data);
    else return dfsTraversal(ptrStartingNodeTree -> ptrRight, data);
}

