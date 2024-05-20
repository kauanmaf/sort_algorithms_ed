#include <iostream>

#include "../sortingAlgorithms.h"
#include "../list/list.h"

using namespace std;


void bubbleSort(Node** head)
{
    // Checando se o ponteiro que aponta para o head é nulo
    if (head == nullptr)
    {
        cout << "Não é possível realizar o bubble sort. Ponteiro nulo" << endl;
        return;
    }

    // Setando os ponteiros para fazer a comparação
    Node* current = (*head);
    Node* iterations = (*head);

    // Enquanto não andamos pela totalidade do pontos (precisamos fazer n-1 vezes)
    while (iterations-> ptrNext != nullptr)
    {
        current = (*head);

        // Enquanto o próximo do atual for diferente do último que setamos
        while (current->ptrNext != nullptr) 
        {
            // Se o payload de current for menor que o payload do próximo
            if (current->iPayload > current->ptrNext->iPayload) 
            {
                // Realizamos o swap
                swapElements(current, current->ptrNext);

            }
            // Setamos o current como o próximo
            current = current->ptrNext;
            
        }
        // Avança o iterations
        iterations = iterations -> ptrNext;

    } 
    return;
};

void optimized_bubbleSort(Node** head)
{
    // Checando se o ponteiro que aponta para o head é nulo
    if (head == nullptr)
    {
        cout << "Não é possível realizar o bubble sort. Ponteiro nulo" << endl;
        return;
    }
    
    // Setando um booleano para saber se já acabamos
    bool swapped;
    // Setando os ponteiros para fazer a comparação
    Node* current = (*head);
    Node* last = nullptr;

    // Utilizamos um do while para fazer pelo menos uma vez
    do {
        // Setamos o swapped como false
        swapped = false;
        // Setamos o atual como o primeiro
        current = (*head);

        // Enquanto o próximo do atual for diferente do último que setamos
        while (current->ptrNext != last) 
        {
            // Se o payload de current for menor que o payload do próximo
            if (current->iPayload > current->ptrNext->iPayload) 
            {
                // Realizamos o swap  
                swapElements(current, current->ptrNext);

                // Setamos swap como true
                swapped = true;
            }
            // Setamos o current como o próximo
            current = current->ptrNext;
        }
        
        // Setamos o último que iteramos como current, pois sabemos que ele é o maior daquela iteração
        // Assim precisamos iterar apenas até ele
        last = current;

    } while (swapped); // Realizamos isso enquanto o swapped for true
    return;
};




