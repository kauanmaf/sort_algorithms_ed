#include <iostream>

#include "../sortingAlgorithms.h"
#include "../list/list.h"

using namespace std;


void countingSort(Node** head)
{
    // Checando se o ponteiro que aponta para o head é nulo
    if (head == nullptr)
    {
        cout << "Não é possível realizar o counting sort. Ponteiro nulo" << endl;
        return;
    }

    // Setando os ponteiros para fazer a comparação
    Node* current = (*head);
    int iMax = current -> iPayload;
    int iTam = 0;

    while (current != nullptr)
    {
        if (current -> iPayload > iMax) 
        {
            iMax = current -> iPayload;
        }
        iTam ++;
        current = current -> ptrNext;
    }

    int arriCount[iMax+1] = {0};

    current = (*head);

    while (current != nullptr)
    {
        arriCount[current->iPayload]++;

        current = current -> ptrNext;
    }

    for (int i = 1; i<=iMax; i++)
    {
        arriCount[i] += arriCount[i-1];
    }
    
    current = (*head);
    while (current->ptrNext != nullptr)
    {
        current = current -> ptrNext;
    }

    int arriSort[iTam] = {0};

    while (current != nullptr)
    {
        arriSort[arriCount[current->iPayload] -1 ] = current -> iPayload;
        arriCount[current->iPayload]--;

        current = current -> ptrPrev;
    }

    current = (*head);

    for(int i = 0; i<iTam; i++)
    {
        current -> iPayload = arriSort[i];
        current = current -> ptrNext;
    }

    return;
};