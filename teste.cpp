#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};

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
void swapElements(Node* ptrFirst, Node* ptrSecond) {
    if (ptrFirst == nullptr || ptrSecond == nullptr) {
        cout << "Não é possível trocar pois algum dos ponteiros é nulo." << endl;
        return;
    }
    int iTemp = ptrFirst->iPayload;
    ptrFirst->iPayload = ptrSecond->iPayload;
    ptrSecond->iPayload = iTemp;
}

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

int main() {
    Node* head = nullptr;
    
    // Inserindo elementos na lista
    insertEnd(&head, 5);
    insertEnd(&head, 3);
    insertEnd(&head, 8);
    insertEnd(&head, 1);
    insertEnd(&head, 7);
    insertEnd(&head, 2);

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
