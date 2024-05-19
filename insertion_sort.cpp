#include <iostream>
#include "sortingAlgorithms.h"
#include "list.h"
using namespace std;


// Função do insertionSort
void insertionSort(Node** head)
{
    // Checamos se a lista nao é vazia
    if (*head == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    
    // Criamos nosso insertvalue, o númeor a ser trocado
    int iInsertValue = 0;
    // Iniciamos os dois ponteiros que iremos precisamos
    // O outerloop andará um para frente por iteração
    Node* ptrOuterLoop = (*head) -> ptrNext;
    // Já o innerloop andará para trás do outer
    Node* ptrInnerLoop = nullptr;
    
    // Iremos até o final da lista
    while (ptrOuterLoop != nullptr)
    {
        // Setamos o nosso insertvalue como o payload do elemento que queremos inserir na lista
        iInsertValue = ptrOuterLoop -> iPayload;
        // Setamos o inner como o prev do outer
        ptrInnerLoop = ptrOuterLoop -> ptrPrev;
        
        // Iremos andar para trás, a não ser que chegamos no final da lista ou que o payload do elemento que estamso for menor que o insertvalue
        while (ptrInnerLoop != nullptr && ptrInnerLoop -> iPayload > iInsertValue)
        {
            // Enquanto essas duas condições não forem satisfeitas 
            // Setamos o payload do elemento acima do innerloop como o paylaod do innerloop
            ptrInnerLoop -> ptrNext -> iPayload = ptrInnerLoop -> iPayload;
            // Andamos para trás com o innerloop
            ptrInnerLoop = ptrInnerLoop -> ptrPrev;
        }
        
        // Se o innerloop for nulo, significa que chegamos ao final da lista
        if (ptrInnerLoop == nullptr)
        {
            // Então setmaos o primeiro elemento como o insertvalue
            (*head) -> iPayload = iInsertValue;
        }

        else
        {   
            // Se não for setamos o próximo do innerloop como o inservalue
            ptrInnerLoop -> ptrNext -> iPayload = iInsertValue;
        }

        // Andamos com o outerloop        
        ptrOuterLoop = ptrOuterLoop -> ptrNext;
    }
};