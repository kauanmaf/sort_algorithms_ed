#include <iostream>
#include <chrono>
#include <iomanip>

#include "list/list.h"
#include "sortingAlgorithms.h"

using namespace std::chrono;
using namespace std;


int main()
{   
    // Número de testes
    const int tests = 100; 
    // Número de algoritmos a serem testados
    const int num_algorithms = 5; 
    // Tamanho de cada lista
    const int num_elements = 10000; 

    // Matriz para armazenar os tempos
    long long times[tests][num_algorithms] = {0}; 

    // Inicializando todas as listas iguais
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* head3 = nullptr;
    Node* head4 = nullptr;
    Node* head5 = nullptr;

    // Para cada teste...
    for (int i = 0; i < tests; ++i)
    {
        // Gera listas com os mesmos elementos
        for (int x = 0; x <= num_elements; x++)
        {
            int num = rand();
            insertEnd(&head1, num);
            insertEnd(&head2, num);
            insertEnd(&head3, num);
            insertEnd(&head4, num);
            insertEnd(&head5, num);
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

        // Limpa as listas
        removeList(&head1);
        removeList(&head2);
        removeList(&head3);
        removeList(&head4);
        removeList(&head5);

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
            }
        }
        cout << endl;
    }
    return 0;
}