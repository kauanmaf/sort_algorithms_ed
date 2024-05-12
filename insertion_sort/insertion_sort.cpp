#include <iostream>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

using std::endl;
using std::cout;
using std::cin;
using std::string;

// Estrutura do nó
typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Protótipos

Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);
void removeList(Node**);

void swapElements(Node*, Node*);
void insertionSort(Node**);


int main()
{   
    // Número de testes
    const int tests = 100; 
    // Número de algoritmos a serem testados
    const int num_algorithms = 1; 
    // Tamanho de cada lista
    const int num_elements = 10000; 

    // Matriz para armazenar os tempos
    long long times[tests][num_algorithms] = {0}; 

    // Inicializando as duas listas iguais
    Node* head1 = nullptr;

    // Para cada teste...
    for (int i = 0; i < tests; ++i)
    {
        // Gera uma lista com os mesmos elementos em head1 e head2
        for (int x = 0; x <= num_elements; x++)
        {
            int num = rand();
            insertEnd(&head1, num);
        }

        // Mede o tempo de execução do select sort não otimizado
        auto timeStart1 = high_resolution_clock::now();
        insertionSort(&head1);
        auto timeStop1 = high_resolution_clock::now();
        auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1).count();
        times[i][0] = timeDuration1;

        // Limpa as listas
        removeList(&head1);
        
        // Exibe os tempos
        cout << "Iteração " << i + 1 << ": " << times[i][0] << endl;
    }
    
    return 0;
}

// Função para criar um nó
Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
};

// Função para exibir uma lista
void displayList(Node* node)
{
    // Se a lista estiver vazia, não faz nada
    if (node == nullptr)
    {
        cout << "A lista esta vazia" << endl;
        return;
    }
    // Se o ponteiro recebido não for o head, não faz nada
    if (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou fim da lista : não é possível realizar o display list" << endl;
        return;
    }
    
    // Nó para percorrer a lista
    Node* temp = node;
    
    cout << "Payload: ";
    // Percorremos a lista até seu fim
    while (temp != nullptr)
    {
        cout << temp -> iPayload << " ";
        temp = temp -> ptrNext;
    }
    
    cout << endl;
    
    return;
};

// Função para inserir um nó no final da lista
void insertEnd(Node** head, int iPayload)
{
    // Cria o nó com o valor
    Node* newNode = createNode(iPayload);

    // Se a lista for vazia, o novo nó passa a ser o head
    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    // Ponteiro para encontrar o final da lista
    Node* temp = (*head);

    // Percorrendo a lista até seu fim
    while (temp -> ptrNext != nullptr)
    {
        temp = temp->ptrNext;
    }

    // O anterior ao novo nó passa a ser o último da lista
    newNode -> ptrPrev = temp;
    // O seguinte ao antes último passa a ser o novo nó
    temp -> ptrNext = newNode;
    return;
};

// Função para limpar a lista
void removeList(Node** head)
{
    // Ponteiros para percorrer a lista
    Node* current = *head;
    Node* next = nullptr;

    // Até chegar ao final da lista, avança e libera o anterior
    while (current != nullptr)
    {
        next = current->ptrNext;
        free(current); 
        current = next;
    }

    // Reseta o head
    (*head) = nullptr; 
};

// Função para trocar os payloads de dois nós
void swapElements(Node* ptrFirst, Node* ptrSecond)
{
    // Se algum deles for nulo, não faz nada
    if (ptrFirst == nullptr || ptrSecond == nullptr)
    {
        cout << "Não é possível trocar pois algum dos ponteiros é nulo." << endl;
        return;
    } 
    
    // Trocando dos payloads
    int iTemp = ptrFirst -> iPayload;
    ptrFirst -> iPayload = ptrSecond -> iPayload;
    ptrSecond -> iPayload = iTemp;
};

// Função do insertionSort
void insertionSort(Node** head)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    
    
    int iInsertValue = 0;
    Node* ptrOuterLoop = (*head) -> ptrNext;
    Node* ptrInnerLoop = nullptr;
    
    while (ptrOuterLoop != nullptr)
    {
        iInsertValue = ptrOuterLoop -> iPayload;
        ptrInnerLoop = ptrOuterLoop -> ptrPrev;
        
        while (ptrInnerLoop != nullptr && ptrInnerLoop -> iPayload > iInsertValue)
        {
            ptrInnerLoop -> ptrNext -> iPayload = ptrInnerLoop -> iPayload;
            ptrInnerLoop = ptrInnerLoop -> ptrPrev;
        }
        
        if (ptrInnerLoop == nullptr)
        {
            (*head) -> iPayload = iInsertValue;
        }
        else
        {
            ptrInnerLoop -> ptrNext -> iPayload = iInsertValue;
        }
        
        ptrOuterLoop = ptrOuterLoop -> ptrNext;
    }
};