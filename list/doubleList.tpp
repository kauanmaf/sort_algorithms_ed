#include <iostream>

#include "list.h"

using namespace std;


// Função para criar um nó
template <typename T>
Node<T>* createNode(T payload)
{
    Node<T>* temp = (Node<T>*) malloc(sizeof(Node<T>));
    temp -> payload = payload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
};

// Função para exibir uma lista
template <typename T>
void displayList(Node<T>* node)
{
    // Se a lista estiver vazia, não faz nada
    if (node == nullptr)
    {
        cout << "A lista esta vazia" << endl;
        return;
    }
    // Se o ponteiro recebido não for o head, não faz nada
    if (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou fim da lista : não é possível realizar o display list" << endl;
        return;
    }
    
    // Nó para percorrer a lista
    Node<T>* temp = node;
    
    cout << "Payload: ";
    // Percorremos a lista até seu fim
    while (temp != nullptr)
    {
        cout << temp -> payload << " ";
        temp = temp -> ptrNext;
    }
    
    cout << endl;
    
    return;
};

// Função para inserir um nó no final da lista
template <typename T>
void insertEnd(Node<T>** head, T payload)
{
    // Cria o nó com o valor
    Node<T>* newNode = createNode(payload);

    // Se a lista for vazia, o novo nó passa a ser o head
    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    // Ponteiro para encontrar o final da lista
    Node<T>* temp = (*head);

    // Percorrendo a lista até seu fim
    while (temp -> ptrNext != nullptr)
    {
        temp = temp->ptrNext;
    }

    // O anterior ao novo nó passa a ser o último da lista
    newNode -> ptrPrev = temp;
    // O seguinte ao antes último passa a ser o novo nó
    temp -> ptrNext = newNode;
    return;
};

// Função para limpar a lista
template <typename T>
void removeList(Node<T>** head)
{
    // Ponteiros para percorrer a lista
    Node<T>* current = *head;
    Node<T>* next = nullptr;

    // Até chegar ao final da lista, avança e libera o anterior
    while (current != nullptr)
    {
        next = current->ptrNext;
        free(current); 
        current = next;
    }

    // Reseta o head
    (*head) = nullptr; 
};

// Função para trocar os payloads de dois nós
template <typename T>
void swapElements(Node<T>* ptrFirst, Node<T>* ptrSecond)
{
    // Se algum deles for nulo, não faz nada
    if (ptrFirst == nullptr || ptrSecond == nullptr)
    {
        cout << "Não é possível trocar pois algum dos ponteiros é nulo." << endl;
        return;
    } 
    
    // Trocando os payloads
    T temp = ptrFirst -> payload;
    ptrFirst -> payload = ptrSecond -> payload;
    ptrSecond -> payload = temp;
};

template <typename T>
Node<T>* searchNodebyValue(Node<T>** head, T value){
    if ((*head) == nullptr)
    {
        cout << "Nao e possivel encontrar o num ponteiro nulo" << endl;
        return nullptr;
    }
    // Setamos um ponteiro como current
    Node<T>* ptrCurrent = (*head);

    // Enquanto não for nulo (chegarmos ao final)
    while(ptrCurrent != nullptr)
    {
        // Checamos se o valor do payload é igual ao valor que estamos procurando 
        if (ptrCurrent -> payload == value)
        {
            // Retornamos o primeiro current que achamos
            return ptrCurrent;
        }

        // Setamos o current como o próximo
        ptrCurrent = ptrCurrent -> ptrNext;
    }

    // Se sairmos do while significa que não encontramos o valor
    cout << "Valor nao encontrado" << endl;
    return nullptr; 
}