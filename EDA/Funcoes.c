#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista ligada
typedef struct Matriz {
    int value;
    int row;
    int col;
    struct Matriz *next;
} Matriz;

// Função para criar um novo nó da lista ligada
Matriz* createMatriz(int value, int row, int col) {
    Matriz* newMatriz = (Matriz*)malloc(sizeof(Matriz));
    newMatriz->value = value;
    newMatriz->row = row;
    newMatriz->col = col;
    newMatriz->next = NULL;
    return newMatriz;
}

// Função para inserir um nó na lista ligada
void insertMatriz(Matriz** head, int value, int row, int col) {
    Matriz* newMatriz = createMatriz(value, row, col);
    if (*head == NULL) {
        *head = newMatriz;
    } else {
        newMatriz->next = *head;
        *head = newMatriz;
    }
}

// Função para verificar se um número pode ser adicionado na posição (row, col)
int isSafe(Matriz* head, int row, int col) {
    while (head != NULL) {
        if (head->row == row || head->col == col)
            return 0; // Se compartilha linha ou coluna, não é seguro
        head = head->next;
    }
    return 1; // Se não compartilha linha ou coluna, é seguro
}

// Função auxiliar para encontrar a soma máxima
void findMaxSumUtil(Matriz* head, int currentSum, int* maxSum) {
    if (head == NULL) {
        if (currentSum > *maxSum) {
            *maxSum = currentSum;
        }
        return;
    }

    Matriz* temp = head;
    while (temp != NULL) {
        if (isSafe(head, temp->row, temp->col)) {
            findMaxSumUtil(temp->next, currentSum + temp->value, maxSum);
        }
        temp = temp->next;
    }
}

// Função para encontrar a soma máxima possível dos inteiros da matriz
int findMaxSum(Matriz* head) {
    int maxSum = 0;
    findMaxSumUtil(head, 0, &maxSum);
    return maxSum;
}

// Função para carregar uma matriz de um arquivo de texto para a lista ligada
Matriz* loadMatrixFromFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return NULL;
    }

    Matriz* head = NULL;
    char line[1000];
    int row = 0;

    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ";");
        int col = 0;
        while (token != NULL) {
            int value = atoi(token);
            insertMatriz(&head, value, row, col);
            col++;
            token = strtok(NULL, ";");
        }
        row++;
    }

    fclose(file);

    return head;
}

// Função para alterar o valor de um nó da lista ligada
void modifyMatrizValue(Matriz* head, int row, int col, int newValue) {
    while (head != NULL) {
        if (head->row == row && head->col == col) {
            head->value = newValue;
            return;
        }
        head = head->next;
    }
}