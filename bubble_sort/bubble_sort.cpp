#include <iostream>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

using std::endl;
using std::cout;
using std::cin;
using std::string;

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Não precisa ter uma struct pra lista encadeada.
// Fazer uma estrutura deixa mais organizado, mas não é obrigatório

Node* createNode(int);
// Retornamos um ponteiro pra ponteiro
void insertFront(Node** , int );
void insertEnd(Node**, int);
void displayList(Node*);
void removeList(Node** );

// Functions for bubble sort
void swapElements(Node*, Node*);
void bubbleSort(Node**);
void optimized_bubbleSort(Node**);

int main() {

    const int tests = 100; 
    const int num_algorithms = 2; 
    const int num_elements = 10000; 

    // Matriz para armazenar os tempos
    long long times[tests][num_algorithms] = {0}; 

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    for (int i = 0; i < tests; ++i) {
        // Gerando uma lista com os mesmos elementos de head1 e head2
        for(int x = 0; x <= num_elements; x++)
        {
            int num = rand();
            insertEnd(&head1, num);
            insertEnd(&head2, num);
        }

        // Insira aqui o código para medir o tempo gasto pelo Bubble Sort para ordenar head1
        auto timeStart1 = high_resolution_clock::now();
        bubbleSort(&head1);
        auto timeStop1 = high_resolution_clock::now();
        auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1).count();
        times[i][0] = timeDuration1;
        // cout << times[i][0] << endl;

        // Insira aqui o código para medir o tempo gasto pelo Bubble Sort otimizado para ordenar head2
        auto timeStart2 = high_resolution_clock::now();
        optimized_bubbleSort(&head2);
        auto timeStop2 = high_resolution_clock::now();
        auto timeDuration2 = duration_cast<nanoseconds>(timeStop2 - timeStart2).count();
        times[i][1] = timeDuration2;

        // Libere a memória alocada para as listas
        removeList(&head1);
        removeList(&head2);
        cout << "Iteracao " << i + 1 << ": " << times[i][0] << " ns - " << times[i][1] << " ns" << endl;
    }

    return 0;
}


Node* createNode(int iPayload){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    return temp;
};

void displayList(Node* node){
    // Imprimimos que a lista está vazia
    if (node == nullptr){
        cout << "A lista esta vazia" << endl;
        return;
    }
    // Se não recebemos o head, não printamos
    if (node -> ptrPrev != nullptr){
        cout << "Meio ou fim da lista : não é possível realizar o display list" << endl;
        return;
    }
    Node* temp = node;
    
    cout << "Payload: ";
    // Percorremos a lista até seu fim
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    return;
};

void insertEnd(Node** head, int iPayload){
        Node* newNode = createNode(iPayload);
    // NewNode->ptrNext = nullptr;

    if (*head == nullptr)
    {
        // NewNode->ptrPrev = nullptr;

        // Derreferenciando um ponteiro
        (*head) = newNode;
        return;
    }

    Node* temp = (*head);

    // Percorremos a lista até seu fim
    while (temp -> ptrNext != nullptr)
    {
        // Vai para frente até ser nulo (último nó)
        temp = temp->ptrNext;
    }

    newNode -> ptrPrev = temp; // newNode aponta para o fim da lista
    temp -> ptrNext = newNode; // Antigo último elemento aponto para o ultimo nó
    return;
};

void removeList(Node** head) {
    Node* current = *head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->ptrNext;
        free(current); 
        current = next;
    }

    *head = nullptr; 
};

void swapElements(Node* ptrFirst, Node* ptrSecond){
    if (ptrFirst == nullptr || ptrSecond == nullptr) {
        cout << "Nao e possivel trocar pois algum dos ponteiros e nulo." << endl;
        return;
    } 
    // Setando o next do first
    ptrFirst -> ptrNext = ptrSecond -> ptrNext;
    // Setando o anterior do próximo do segundo como o ptrFirst
    if (ptrSecond -> ptrNext != nullptr) ptrSecond -> ptrNext -> ptrPrev = ptrFirst;

    // Fazemos o mesmo para o segundo nó
    ptrSecond -> ptrPrev = ptrFirst -> ptrPrev;
    if (ptrFirst -> ptrPrev != nullptr) ptrFirst -> ptrPrev -> ptrNext = ptrSecond;

    // Trocamos agora os dois ponteiros que faltam
    ptrFirst -> ptrPrev = ptrSecond;
    ptrSecond -> ptrNext = ptrFirst;
};

void bubbleSort(Node** head){
    // Checando se o ponteiro que aponta par ao head é nula
    if (head == nullptr){
        cout << "Não é possível realizar o bubble sort. Ponteiro Nulo" << endl;
        return;
    }

    // Setando os ponteiros para fazer a comparação
    Node* current = (*head);
    Node* iterations = (*head);

    // enquanto não andamos pela totalidade do pontos (precisamos fazer n-1 vezes)
    while (iterations-> ptrNext != nullptr){
        // enquanto o próximo do atual for diferente do ultimo que setamos
        current = (*head);

        while (current->ptrNext != nullptr) 
        {
            // cout << current -> iPayload << endl;
            // Se o payload de current for menor que o payload do próximo
            if (current->iPayload > current->ptrNext->iPayload) 
            {
                // Checamos se é o primeiro elemento para atualizar o head também
                if (current -> ptrPrev == nullptr) (*head) = current -> ptrNext;

                // Realizamos o swap  
                swapElements(current, current->ptrNext);

                // Setamos o current como o anterior para trocar os ponteiros.
                current = current -> ptrPrev;

            }
            // Setamos o current como o próximo
            current = current->ptrNext;
            
        }
        // Setamos o último que iteramos como current, pois sabemos que ele é o maior daquela iteração
        // Assim precisamos iterar apenas até ele
        iterations = iterations -> ptrNext;

    } 
    return;
};

void optimized_bubbleSort(Node** head){
    // Checando se o ponteiro que aponta par ao head é nula
    if (head == nullptr){
        cout << "Não é possível realizar o bubble sort. Ponteiro Nulo" << endl;
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

        // enquanto o próximo do atual for diferente do ultimo que setamos
        while (current->ptrNext != last) 
        {
            // Se o payload de current for menor que o payload do próximo
            if (current->iPayload > current->ptrNext->iPayload) 
            {
                // Checamos se é o primeiro elemento para atualizar o head também
                if (current -> ptrPrev == nullptr) (*head) = current -> ptrNext;

                // Realizamos o swap  
                swapElements(current, current->ptrNext);

                // Setamos o current como o anterior para trocar os ponteiros.
                current = current -> ptrPrev;
                // Setamos swap como true
                swapped = true;
            }
            // Setamoso  current como o próximo
            current = current->ptrNext;
        }
        
        // Setamos o último que iteramos como current, pois sabemos que ele é o maior daquela iteração
        // Assim precisamos iterar apenas até ele
        last = current;

    } while (swapped); // Realizamos isso enquanto o swapped for true
    return;
};





