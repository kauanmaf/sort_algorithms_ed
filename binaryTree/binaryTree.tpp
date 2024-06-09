#include <iostream>

#include "binaryTree.h"
#include "../list/list.h"

using namespace std;

// Função para criar um nó de árvore
template <typename T>
NodeTree<T>* newNodeTree(T data)
{
    // Alocando memória
    NodeTree<T>* tmp = (NodeTree<T>*) malloc(sizeof(NodeTree<T>));
    // Se não for possível alocar memória, retorna um erro
    if (tmp == nullptr)
    {
        cerr << "Erro em newNodeTree: malloc" << endl;
        exit(1);
    }
    
    // Inicializando os atributos do nó
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

    // Se o valor for menor que o payload do nó, insere o novo nó na esquerda
    if (data < startingNodeTree -> payload) startingNodeTree -> ptrLeft = insertNodeTree(startingNodeTree -> ptrLeft, data);

    // Se for maior, inserimos na direita
    else startingNodeTree -> ptrRight = insertNodeTree(startingNodeTree -> ptrRight, data);

    return startingNodeTree;

}

// Função para navegar pela árvore por BFS
template <typename T>
void bfsTraversal(NodeTree<T>* startingNodeTree)
{
    // Se a árvore for vazia, não faz nada
    if (startingNodeTree == nullptr) return;

    // Inicializa a lista para armazenar os nós da árvore
    Node<NodeTree<T>*>* head = nullptr; 
    // Ponteiro para o nó analisado no momento
    Node<NodeTree<T>*>* current = nullptr;

    // Adiciona a raiz da árvore na lista
    insertEnd(&head, startingNodeTree);

    // O current passa a ser o primeiro elemento da lista
    current = head;

    // Enquanto não acabar a lista...
    while (current != nullptr)
    {
        // Printa o valor do nó atual
        cout << current -> payload -> payload << " ";

        // Se ele tiver filho à esquerda, adiciona-o na lista
        if (current -> payload -> ptrLeft != nullptr)
        {
            insertEnd(&head, current -> payload -> ptrLeft);
        }
        // Se ele tiver filho à direita, adiciona-o na lista
        if (current -> payload -> ptrRight != nullptr)
        {
            insertEnd(&head, current -> payload -> ptrRight);
        }

        // Avança o current
        current = current -> ptrNext;
    }
    cout << endl;
}

// Função para procurar um valor na árvore pelo BFS
template <typename T>
NodeTree<T>* searchBfs(NodeTree<T>* startingNodeTree, T data)
{
    // Se a árvore for vazia, não faz nada
    if (startingNodeTree == nullptr) return nullptr;

    // Inicializa a lista para armazenar os nós da árvore
    Node<NodeTree<T>*>* head = nullptr; 
    // Ponteiro para o nó analisado no momento
    Node<NodeTree<T>*>* current = nullptr;

    // Adiciona a raiz da árvore na lista
    insertEnd(&head, startingNodeTree);

    // O current passa a ser o primeiro elemento da lista
    current = head;

    // Enquanto não acabar a lista...
    while (current != nullptr)
    {
        // Se o valor do nó atual for o valor que estamos procurando, retorna ele
        if (current -> payload -> payload == data)
        {
            return current -> payload;
        }

        // Se ele tiver filho à esquerda, adiciona-o na lista
        if (current -> payload -> ptrLeft != nullptr)
        {
            insertEnd(&head, current -> payload -> ptrLeft);
        }
        // Se ele tiver filho à direita, adiciona-o na lista
        if (current -> payload -> ptrRight != nullptr)
        {
            insertEnd(&head, current -> payload -> ptrRight);
        }

        // Avança o current
        current = current -> ptrNext;
        
    }
    // Se chegar ao final, não encontrou o nó
    cout << "Nó não encontrado" << endl;
    return nullptr;
}

// Função para limpar a árvore
template <typename T>
void cleanTree(NodeTree<T>* ptrStartingNode)
{
    // Se o nó não for nulo...
    if (ptrStartingNode != nullptr)
    {
        // Limpa as subárvores da esquerda e da direita
        cleanTree(ptrStartingNode -> ptrLeft);
        cleanTree(ptrStartingNode -> ptrRight);
        // Libera a memória do nó
        free(ptrStartingNode);
    }
}

// Função para encontrar o nó de menor valor de uma árvore
template <typename T>
NodeTree<T>* lesserLeaf(NodeTree<T>* ptrStartingNode)
{
    // Ponteiro para navegar pela árvore
    NodeTree<T>* ptrCurrent = ptrStartingNode;
    
    // Enquanto o current e seu filho da esquerda não forem nulos...
    while (ptrCurrent && ptrCurrent -> ptrLeft != nullptr)
    {
        // Avança o current para a esquerda
        ptrCurrent = ptrCurrent -> ptrLeft;
    }
    
    return ptrCurrent;
}

// Função para buscar na árvore pelo DFS
template <typename T>
NodeTree<T>* dfsTraversal(NodeTree<T>* ptrStartingNodeTree, T data)
{
    // Se o valor do nó for nulo, acabou a árvore
    if (ptrStartingNodeTree == nullptr) return nullptr;
    // Se for igual ao valor procurado, retorna ele
    if (ptrStartingNodeTree->payload == data) return ptrStartingNodeTree;

    // Procurando na árvore da esquerda
    NodeTree<T>* leftResult = dfsTraversal(ptrStartingNodeTree->ptrLeft, data);
    // Se ela for diferente de nula, retorna ela mesma
    if (leftResult != nullptr) return leftResult;
    
    // Se não, busca na árvore da direita
    return dfsTraversal(ptrStartingNodeTree->ptrRight, data);
}



