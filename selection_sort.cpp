#include <iostream>

#include "sortingAlgorithms.h"
#include "list.h"

using namespace std;


// Função do selection sort não otimizado
void selectionSort(Node** head)
{
    // Se a lista for vazia, não faz nada
    if (head == nullptr)
    {
        cout << "Não é possível realizar o selection sort. Ponteiro nulo" << endl;
        return;
    }

    // Ponteiro da posição a ser atualizada
    Node* position = (*head);
    // Poteiro que percorrerá a lista
    Node* current = position -> ptrNext;

    // Até chegar à última posição...
    while (position -> ptrNext != nullptr)
    {
        // Até chegar ao final da lista...
        while (current != nullptr) 
        {
            // Se o payload do current for menor que o payload da posição, troca os payloads
            if (current -> iPayload < position -> iPayload) 
            {
                swapElements(position, current);
            }
            
            // Avança o current
            current = current->ptrNext;
        }
        
        // Avança a posição e trás de volta o current
        position = position -> ptrNext;
        current = position -> ptrNext;
    } 
    return;
};

// Função do selection sort otimizado
void optimizedSelectionSort(Node** head)
{
    // Se a lista for vazia, não faz nada
    if (head == nullptr)
    {
        cout << "Não é possível realizar o bubble sort. Ponteiro nulo" << endl;
        return;
    }

    // Ponteiro da posição a ser atualizada
    Node* position = (*head);
    // Ponteiro para percorrer a lista
    Node* current = position->ptrNext;
    // Ponteiro que ficará apontando para o nó com menor payload
    Node* ptrMin = position;

    // Menor payload encontrado
    int iMin = 0;

    // Até chegar à última posição...
    while (position-> ptrNext != nullptr)
    {
        // Configura o iMin para ser o payload do nó posição
        iMin = position -> iPayload;
        // Inicia o ptrMin como o próprio posição
        Node* ptrMin = position;

        // Até chegar ao final da lista...
        while (current != nullptr) 
        {
            // Se o payload de current for menor que o iMin...
            if (current -> iPayload < iMin) 
            {
                // O ponteiro com menor payload passa a ser o current
                ptrMin = current;
                // O payload mínimo passa a ser o payload do current
                iMin = current -> iPayload;
            }
            // Avança o current
            current = current -> ptrNext;
            
        }
        
        // Troca os payloads da posição e do que contém o payload mínimo
        swapElements(position, ptrMin);
        
        // Avança a posição
        position = position -> ptrNext;
        current = position -> ptrNext;
    } 
    return;
};
