#include <iostream>

#include "../sortingAlgorithms.h"
#include "../list/list.h"

using namespace std;

template <typename T>
// Função do insertionSort
void insertionSort(Node<T>** head)
{
    // Checamos se a lista não é vazia
    if (*head == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    
    // Criamos nosso insertvalue, o número a ser trocado
    int iInsertValue = 0;
    // Iniciamos os dois ponteiros que iremos precisar
    // O outerloop andará um para frente por iteração
    Node<T>* ptrOuterLoop = (*head) -> ptrNext;
    // Já o innerloop andará para trás do outer
    Node<T>* ptrInnerLoop = nullptr;
    
    // Iremos até o final da lista
    while (ptrOuterLoop != nullptr)
    {
        // Setamos o nosso insertvalue como o payload do elemento que queremos inserir na lista
        iInsertValue = ptrOuterLoop -> payload;
        // Setamos o inner como o prev do outer
        ptrInnerLoop = ptrOuterLoop -> ptrPrev;
        
        // Iremos andar para trás, a não ser que cheguemos no final da lista ou que o payload do elemento que estamos seja menor que o insertvalue
        while (ptrInnerLoop != nullptr && ptrInnerLoop -> payload > iInsertValue)
        {
            // Enquanto essas duas condições não forem satisfeitas,
            // setamos o payload do elemento acima do innerloop como o payload do innerloop
            ptrInnerLoop -> ptrNext -> payload = ptrInnerLoop -> payload;
            // Andamos para trás com o innerloop
            ptrInnerLoop = ptrInnerLoop -> ptrPrev;
        }
        
        // Se o innerloop for nulo, significa que chegamos ao final da lista
        if (ptrInnerLoop == nullptr)
        {
            // Então setamos o primeiro elemento como o insertvalue
            (*head) -> payload = iInsertValue;
        }

        else
        {   
            // Se não for setamos o próximo do innerloop como o inservalue
            ptrInnerLoop -> ptrNext -> payload = iInsertValue;
        }

        // Andamos com o outerloop        
        ptrOuterLoop = ptrOuterLoop -> ptrNext;
    }
};
