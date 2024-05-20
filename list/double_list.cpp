#include <iostream>

#include "list.h"

using namespace std;


// Função para criar um nó
Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
};

// Função para exibir uma lista
void displayList(Node* node)
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
    Node* temp = node;
    
    cout << "Payload: ";
    // Percorremos a lista até seu fim
    while (temp != nullptr)
    {
        cout << temp -> iPayload << " ";
        temp = temp -> ptrNext;
    }
    
    cout << endl;
    
    return;
};

// Função para inserir um nó no final da lista
void insertEnd(Node** head, int iPayload)
{
    // Cria o nó com o valor
    Node* newNode = createNode(iPayload);

    // Se a lista for vazia, o novo nó passa a ser o head
    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    // Ponteiro para encontrar o final da lista
    Node* temp = (*head);

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
void removeList(Node** head)
{
    // Ponteiros para percorrer a lista
    Node* current = *head;
    Node* next = nullptr;

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
void swapElements(Node* ptrFirst, Node* ptrSecond)
{
    // Se algum deles for nulo, não faz nada
    if (ptrFirst == nullptr || ptrSecond == nullptr)
    {
        cout << "Não é possível trocar pois algum dos ponteiros é nulo." << endl;
        return;
    } 
    
    // Trocando os payloads
    int iTemp = ptrFirst -> iPayload;
    ptrFirst -> iPayload = ptrSecond -> iPayload;
    ptrSecond -> iPayload = iTemp;
};