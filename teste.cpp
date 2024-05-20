#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};

// Protótipos
Node* createNode(int);
void displayList(Node*);
void insertEnd(Node**, int);
void removeList(Node**);
void swapElements(Node*, Node*);
void displayArray(int[], int);
void countingSort(Node**);


int main() {
    Node* head = nullptr;
    
    // Inserindo elementos na lista
    insertEnd(&head, 5);
    insertEnd(&head, 3);
    insertEnd(&head, 8);
    insertEnd(&head, 5);
    insertEnd(&head, 3);
    insertEnd(&head, 2);
    insertEnd(&head, 6);
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 2);
    insertEnd(&head, 4);

    // Exibindo a lista antes da ordenação
    cout << "Lista original: ";
    displayList(head);

    // Ordenando a lista
    countingSort(&head);

    // Exibindo a lista após a ordenação
    cout << "Lista ordenada: ";
    displayList(head);

    // Limpando a lista
    removeList(&head);

    return 0;
}


// Função para criar um nó
Node* createNode(int iPayload) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    return temp;
}

// Função para exibir uma lista
void displayList(Node* node) {
    if (node == nullptr) {
        cout << "A lista está vazia" << endl;
        return;
    }
    if (node->ptrPrev != nullptr) {
        cout << "Meio ou fim da lista: não é possível realizar o display list" << endl;
        return;
    }
    Node* temp = node;
    cout << "Payload: ";
    while (temp != nullptr) {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    cout << endl;
}

// Função para inserir um nó no final da lista
void insertEnd(Node** head, int iPayload) {
    Node* newNode = createNode(iPayload);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->ptrNext != nullptr) {
        temp = temp->ptrNext;
    }
    temp->ptrNext = newNode;
    newNode->ptrPrev = temp;
}

// Função para limpar a lista
void removeList(Node** head) {
    Node* current = *head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->ptrNext;
        free(current);
        current = next;
    }
    *head = nullptr;
}

// Função para trocar os payloads de dois nós
void swapElements(Node* ptrFirst, Node* ptrSecond){
    if (ptrFirst == nullptr || ptrSecond == nullptr) {
        cout << "Não é possível trocar pois algum dos ponteiros é nulo." << endl;
        return;
    }
    int iTemp = ptrFirst->iPayload;
    ptrFirst->iPayload = ptrSecond->iPayload;
    ptrSecond->iPayload = iTemp;
}

// Função para exibir um array
void displayArray(int arriValores[], int iTam)
{
    cout << "Array: ";
    for (int i = 0; i < iTam; i++)
    {
        cout << arriValores[i] << " ";
    }
    cout << endl;
}


void countingSort(Node** head)
{
    // Checando se o ponteiro que aponta para o head é nulo
    if (head == nullptr)
    {
        cout << "Não é possível realizar o counting sort. Ponteiro nulo" << endl;
        return;
    }

    cout << "======================================================= INÍCIO DO ALGORITMO =======================================================" << endl;
    cout << "-> Primeiro, precisamos encontrar o maior valor da lista:" << endl;

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
    
    cout << "iMax: " << iMax << endl;
    cout << "-> Ao mesmo tempo, calculamos o tamanho da lista:" << endl;
    cout << "iTam: " << iTam << endl;

    cout << "-> Em seguida, criamos um array de zeros do tamanho do maior valor mais 1" << endl;
    int arriCount[iMax+1] = {0};
    displayArray(arriCount, iMax + 1);

    cout << "-> Após isso, realiza-se a contagem de quantos elementos de cada tipo existem na lista." << endl;
    cout << "-> Para isso, a cada elemento da lista, somamos 1 à posição do array criado de índice correspondente a esse valor." << endl;

    current = (*head);

    while (current != nullptr)
    {
        arriCount[current->iPayload]++;

        current = current -> ptrNext;
    }
    
    displayArray(arriCount, iMax + 1);

    cout << "-> Agora, fazemos uma soma cumulativa nesse array, de modo que o valor no índice i corresponde a quantos valores menores ou iguais a i existem na lista." << endl;

    for (int i = 1; i<=iMax; i++)
    {
        arriCount[i] += arriCount[i-1];
    }
    
    displayArray(arriCount, iMax + 1);
    
    current = (*head);
    while (current->ptrNext != nullptr)
    {
        current = current -> ptrNext;
    }

    cout << "-> Para lista encadeada, criamos nesse passo um novo array de zeros, mas agora do tamanho da lista." << endl;
    
    int arriSort[iTam] = {0};
    
    displayArray(arriSort, iTam);

    cout << "-> A seguir, vem de fato a 'ordenação' da lista." << endl;
    cout << "-> A ideia é navegar na lista de trás pra frente inserindo cada payload na sua posição correta na lista ordenada." << endl;
    cout << "-> Essa posição é descoberta olhando para o array de contagem acumulada." << endl;
    cout << "-> O valor i irá na posição 'arriCount[i] - 1' pois existem 'arriCount[i]' elementos menores ou iguais que i." << endl;
    cout << "-> Para finalizar esse processo, é decrementado 1 da lista acumulada na posição i para garantir que não haverá sobreposição." << endl;

    while (current != nullptr)
    {
        arriSort[arriCount[current->iPayload] -1 ] = current -> iPayload;
        arriCount[current->iPayload]--;

        current = current -> ptrPrev;
    }

    displayArray(arriSort, iTam);

    cout << "-> Por fim, apenas substituímos os valores desse array auxiliar na lista original." << endl;
    
    current = (*head);

    for(int i = 0; i<iTam; i++)
    {
        current -> iPayload = arriSort[i];
        current = current -> ptrNext;
    }
    
    cout << "======================================================= FIM DO ALGORITMO =======================================================" << endl;

    return;
};
