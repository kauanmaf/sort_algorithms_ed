#include <iostream>
#include <chrono>

#include "list.h"
#include "sortingAlgorithms.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

using namespace std;


int main()
{   
    // Número de testes
    const int tests = 100; 
    // Número de algoritmos a serem testados
    const int num_algorithms = 2; 
    // Tamanho de cada lista
    const int num_elements = 10000; 

    // Matriz para armazenar os tempos
    long long times[tests][num_algorithms] = {0}; 

    // Inicializando as duas listas iguais
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Para cada teste...
    for (int i = 0; i < tests; ++i)
    {
        // Gera uma lista com os mesmos elementos em head1 e head2
        for (int x = 0; x <= num_elements; x++)
        {
            int num = rand();
            insertEnd(&head1, num);
            insertEnd(&head2, num);
        }

        // Mede o tempo de execução do select sort não otimizado
        auto timeStart1 = high_resolution_clock::now();
        bubbleSort(&head1);
        auto timeStop1 = high_resolution_clock::now();
        auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1).count();
        times[i][0] = timeDuration1;

        auto timeStart2 = high_resolution_clock::now();
        optimized_bubbleSort(&head2);
        auto timeStop2 = high_resolution_clock::now();
        auto timeDuration2 = duration_cast<nanoseconds>(timeStop2 - timeStart2).count();
        times[i][0] = timeDuration2;

        // Limpa as listas
        removeList(&head1);
        removeList(&head2);
        
        // Exibe os tempos
        cout << "Iteração " << i + 1 << ": " << times[i][0] << endl;
    }
    
    return 0;
}