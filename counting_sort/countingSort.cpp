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
    // Criamos uma variável com o valor máximo do current
    int iMax = current -> iPayload;
    // Salvando o tamanho do array, para atualizarmos na iteração
    int iTam = 0;

    // Iteramos sobre todos os elementos para descobrirmos o valor do maior e o tamanho do array
    while (current != nullptr)
    {
        // Se encontrarmos um payload maior, setamos o max como current
        if (current -> iPayload > iMax) iMax = current -> iPayload;

        // Aumentamos um em tamanho
        iTam ++;
        // Setamos current como o próximo
        current = current -> ptrNext;
    }

    // Criamos um array de 0's do tamanho de iMax+1, o qual contará quantas vezes cada elemento aparece 
    int arriCount[iMax+1] = {0};

    // Setamos o current como head novamente
    current = (*head);

    // Vamos até o final da lista contando cada um dos elementos
    while (current != nullptr)
    {
        // Somamos um na posição ipayload de cada arricount
        arriCount[current->iPayload]++;

        // setamos current como o próximo
        current = current -> ptrNext;
    }

    // Fazemos agora a distribuição cumulativa de tudo, somando o anterior com o atual
    for (int i = 1; i<=iMax; i++) arriCount[i] += arriCount[i-1];
    
    // Vamos agora até o final da lista
    current = (*head);

    while (current->ptrNext != nullptr) current = current -> ptrNext;

    // Criamos uma lista do tamanho da lista
    int arriSort[iTam] = {0};

    // Vamos agora criar um array ordenado
    while (current != nullptr)
    {
        // Atualizando o arriSort
        arriSort[arriCount[current->iPayload] -1] = current -> iPayload;
        // Diminuindo 1 do arricount
        arriCount[current->iPayload]--;

        // Setando o próximo como current
        current = current -> ptrPrev;
    }

    // Por fim, setamos o current como head
    current = (*head);

    // Percorremos as listas mudando os payloads
    for(int i = 0; i<iTam; i++)
    {
        current -> iPayload = arriSort[i];
        current = current -> ptrNext;
    }

    return;
};