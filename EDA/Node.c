#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista ligada
typedef struct Node {
    int value;
    int row;
    int col;
    struct Node *next;
} Node;

// Função para criar um novo nó da lista ligada
Node* createNode(int value, int row, int col) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó na lista ligada
void insertNode(Node** head, int value, int row, int col) {
    Node* newNode = createNode(value, row, col);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

// Função para verificar se um número pode ser adicionado na posição (row, col)
int isSafe(Node* head, int row, int col) {
    while (head != NULL) {
        if (head->row == row || head->col == col)
            return 0; // Se compartilha linha ou coluna, não é seguro
        head = head->next;
    }
    return 1; // Se não compartilha linha ou coluna, é seguro
}

// Função auxiliar para encontrar a soma máxima
void findMaxSumUtil(Node* head, int currentSum, int* maxSum) {
    if (head == NULL) {
        if (currentSum > *maxSum) {
            *maxSum = currentSum;
        }
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (isSafe(head, temp->row, temp->col)) {
            findMaxSumUtil(temp->next, currentSum + temp->value, maxSum);
        }
        temp = temp->next;
    }
}

// Função para encontrar a soma máxima possível dos inteiros da matriz
int findMaxSum(Node* head) {
    int maxSum = 0;
    findMaxSumUtil(head, 0, &maxSum);
    return maxSum;
}