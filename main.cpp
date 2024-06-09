#include <iostream>
#include <chrono>
#include <iomanip>

#include "list/list.h"
#include "sortingAlgorithms.h"
#include "binaryTree/binaryTree.h"


using namespace std::chrono;
using namespace std;


int main()
{   
    ///// TESTES DE ORDENAMENTO /////

    // Número de testes
    const int tests = 100; 
    // Número de algoritmos a serem testados
    const int num_algorithms = 6; 
    // Tamanho de cada lista
    const int num_elements = 10000; 

    // Matriz para armazenar os tempos
    long long times[tests][num_algorithms] = {0}; 

    // Inicializando todas as listas iguais
    Node<int>* head1 = nullptr;
    Node<int>* head2 = nullptr;
    Node<int>* head3 = nullptr;
    Node<int>* head4 = nullptr;
    Node<int>* head5 = nullptr;
    Node<int>* head6 = nullptr;

    // Para cada teste...
    for (int i = 0; i < tests; ++i)
    {
        // Gera listas com os mesmos elementos
        for (int x = 0; x <= num_elements; x++)
        {
            int num = rand() % 100 + 1;
            insertEnd(&head1, num);
            insertEnd(&head2, num);
            insertEnd(&head3, num);
            insertEnd(&head4, num);
            insertEnd(&head5, num);
            insertEnd(&head6, num);
        }

        // Mede o tempo de execução de cada algoritmo
        auto timeStart1 = high_resolution_clock::now();
        bubbleSort(&head1);
        auto timeStop1 = high_resolution_clock::now();
        auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1).count();
        times[i][0] = timeDuration1;

        auto timeStart2 = high_resolution_clock::now();
        optimized_bubbleSort(&head2);
        auto timeStop2 = high_resolution_clock::now();
        auto timeDuration2 = duration_cast<nanoseconds>(timeStop2 - timeStart2).count();
        times[i][1] = timeDuration2;
        
        auto timeStart3 = high_resolution_clock::now();
        selectionSort(&head3);
        auto timeStop3 = high_resolution_clock::now();
        auto timeDuration3 = duration_cast<nanoseconds>(timeStop3 - timeStart3).count();
        times[i][2] = timeDuration3;

        auto timeStart4 = high_resolution_clock::now();
        optimizedSelectionSort(&head4);
        auto timeStop4 = high_resolution_clock::now();
        auto timeDuration4 = duration_cast<nanoseconds>(timeStop4 - timeStart4).count();
        times[i][3] = timeDuration4;

        auto timeStart5 = high_resolution_clock::now();
        insertionSort(&head5);
        auto timeStop5 = high_resolution_clock::now();
        auto timeDuration5 = duration_cast<nanoseconds>(timeStop5 - timeStart5).count();
        times[i][4] = timeDuration5;

        auto timeStart6 = high_resolution_clock::now();
        insertionSort(&head6);
        auto timeStop6 = high_resolution_clock::now();
        auto timeDuration6 = duration_cast<nanoseconds>(timeStop6 - timeStart6).count();
        times[i][5] = timeDuration6;

        // Limpa as listas
        removeList(&head1);
        removeList(&head2);
        removeList(&head3);
        removeList(&head4);
        removeList(&head5);
        removeList(&head6);

        // Exporta os tempos formatados
        cout << "Iteração " << i + 1 << ":" << endl;
        for (int algo = 0; algo < num_algorithms; ++algo)
        {
            switch (algo)
            {
                case 0:
                cout << "Bubble sort: " << setw(23) << times[i][algo] << " ns" << endl;
                break;
                case 1:
                cout << "Optimized bubble sort: " << setw(13) << times[i][algo] << " ns" << endl;
                break;
                case 2:
                cout << "Selection sort: " << setw(20) << times[i][algo] << " ns" << endl;
                break;
                case 3:
                cout << "Optimized selection sort: " << setw(10) << times[i][algo] << " ns" << endl;
                break;
                case 4:
                cout << "Insertion sort: " << setw(20) << times[i][algo] << " ns" << endl;
                break;
                case 5:
                cout << "Counting sort: " << setw(21) << times[i][algo] << " ns" << endl;
                break;
            }
        }
        cout << endl;
    }

    ///////////////////////////////////////////////////////////////////////////////////

    ///// TESTES DE ÁRVORES /////
    // Números de testes, de experimentos e de elementos por estrutura e range dos valores
    const int tests = 100; 
    const int num_algorithms = 4; 
    const int num_elements = 10000; 
    const int range_elements = 100000; 

    // Inicializando a matriz de resultados
    long long times[tests][num_algorithms] = {0}; 

    // Em cada teste...
    for (int i = 0; i < tests; ++i)
    {
        // Inicializa um array com os valores a serem colocados nas estruturas
        int *arrivalues = (int *)malloc(num_elements * sizeof(int));

        // Inicializa as estruturas
        Node<int>* list = nullptr;
        NodeTree<int>* tree = nullptr;

        // Para cada elemento...
        for (int x = 0; x < num_elements; x++)
        {
            // Sorteia um número aleatório
            int num = rand() % range_elements + 1;
            // Adiciona-o no array
            arrivalues[x] = num;
        }

        // Conta o tempo de criação da lista
        auto startCreateList = high_resolution_clock::now();
        // Para cada valor no array...
        for (int x = 0; x < num_elements; x++)
        {
            // Adiciona-o na lista
            int num = arrivalues[x];
            insertFront(&list, num);
        }
        auto stopCreateList = high_resolution_clock::now();
        auto durationCreateList = duration_cast<nanoseconds>(stopCreateList - startCreateList).count();
        times[i][0] = durationCreateList;

        // Conta o tempo de criação da árvore
        auto startCreateTree = high_resolution_clock::now();
        // Para cada valor no array...
        for (int x = 0; x < num_elements; x++)
        {
            // Adiciona-o na árvore
            int num = arrivalues[x];
            tree = insertNodeTree(tree, num);
        }
        auto stopCreateTree = high_resolution_clock::now();
        auto durationCreateTree = duration_cast<nanoseconds>(stopCreateTree - startCreateTree).count();
        times[i][1] = durationCreateTree;

        // Sorteando um valor aleatório dentre os que estão nas estruturas para procurar
        int indexElement = rand() % num_elements + 1;
        int searchElement = arrivalues[indexElement];

        // Contando o tempo de busca na lista
        auto startSearchList = high_resolution_clock::now();
        Node<int>* foundNodeList = searchNodebyValue(&list, searchElement);
        auto stopSearchList = high_resolution_clock::now();
        auto durationSearchList = duration_cast<nanoseconds>(stopSearchList - startSearchList).count();
        times[i][2] = durationSearchList;

        // Contando o tempo de busca na árvore por BFS
        auto startSearchTree = high_resolution_clock::now();
        NodeTree<int>* foundNodeTree = searchBfs(tree, searchElement);
        auto stopSearchTree = high_resolution_clock::now();
        auto durationSearchTree = duration_cast<nanoseconds>(stopSearchTree - startSearchTree).count();
        times[i][3] = durationSearchTree;

        // Contando o tempo de busca na árvore por DFS
        auto startSearchTreeDFS = high_resolution_clock::now();
        NodeTree<int>* foundNodeTreeDFS = dfsTraversal(tree, searchElement);
        auto stopSearchTreeDFS = high_resolution_clock::now();
        auto durationSearchTreeDFS = duration_cast<nanoseconds>(stopSearchTreeDFS - startSearchTreeDFS).count();
        times[i][4] = durationSearchTreeDFS;

        // Limpa as listas e árvores
        removeList(&list);
        cleanTree(tree);
        free(arrivalues);

        // Exporta os tempos formatados
        cout << "Iteração " << i + 1 << ":" << endl;
        cout << "Criação de lista: " << setw(29) << times[i][0] << " ns" << endl;
        cout << "Criação de árvore: " << setw(28) << times[i][1] << " ns" << endl;
        cout << "Busca em lista: " << setw(31) << times[i][2] << " ns" << endl;
        cout << "Busca em árvore (BFS): " << setw(24) << times[i][3] << " ns" << endl;
        cout << "Busca em árvore (DFS): " << setw(24) << times[i][4] << " ns" << endl;
        cout << "Criação + busca de lista: " << setw(21) << times[i][0] + times[i][2] << " ns" << endl;
        cout << "Criação + busca de árvore (BFS): " << setw(14) << times[i][1] + times[i][3] << " ns" << endl;
        cout << "Criação + busca de árvore (DFS): " << setw(14) << times[i][1] + times[i][4] << " ns" << endl;
        cout << endl;
    }
    return 0;
}