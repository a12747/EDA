#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 
 * Estrutura da Matriz
 */
typedef struct Matriz {
    int value;
    int row;
    int col;
    struct Matriz *next;
} Matriz;

/**
 * @brief Create a Matriz object
 * Criar uma nova matriz
 * @param value 
 * @param row 
 * @param col 
 * @return Matriz* 
 */
Matriz* createMatriz(int value, int row, int col) {
    Matriz* newMatriz = (Matriz*)malloc(sizeof(Matriz));
    newMatriz->value = value;
    newMatriz->row = row;
    newMatriz->col = col;
    newMatriz->next = NULL;
    return newMatriz;
}

/**
 * @brief 
 * Inserir um novo valor na matriz
 * @param head 
 * @param value 
 * @param row 
 * @param col 
 */
void insertMatriz(Matriz** head, int value, int row, int col) {
    Matriz* newMatriz = createMatriz(value, row, col);
    if (*head == NULL) {
        *head = newMatriz;
    } else {
        newMatriz->next = *head;
        *head = newMatriz;
    }
}

/**
 * @brief 
 * Função para verificar se um número pode ser adicionado na posição (row, col)
 * @param head 
 * @param row 
 * @param col 
 * @return int 
 */
int isSafe(Matriz* head, int row, int col) {
    while (head != NULL) {
        if (head->row == row || head->col == col)
            return 0; // Se compartilha linha ou coluna, não é seguro
        head = head->next;
    }
    return 1; // Se não compartilha linha ou coluna, é seguro
}

/**
 * @brief Função auxiliar para encontrar a soma máxima
 * 
 * @param head 
 * @param currentSum 
 * @param maxSum 
 */
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

/**
 * @brief Função para encontrar a soma máxima possível dos inteiros da matriz
 * 
 * @param head 
 * @return int 
 */
int findMaxSum(Matriz* head) {
    int maxSum = 0;
    findMaxSumUtil(head, 0, &maxSum);
    return maxSum;
}

/**
 * @brief Função para carregar uma matriz de um ficheiro de texto para a lista ligada
 * 
 * @param filename 
 * @return Matriz* 
 */
Matriz* loadMatrixFromFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o ficheiro.\n");
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

/**
 * @brief Função para alterar o valor de um nó da lista ligada
 * 
 * @param head 
 * @param row 
 * @param col 
 * @param newValue 
 */
void modifyMatrizValue(Matriz* head, int row, int col, int newValue) {
    while (head != NULL) {
        if (head->row == row && head->col == col) {
            head->value = newValue;
            return;
        }
        head = head->next;
    }
}

/**
 * @brief Função para inserir uma nova linha na matriz
 * 
 * @param head 
 * @param rowCount 
 * @param colCount 
 * @param rowNumber 
 */
void insertRow(Matriz** head, int* rowCount, int colCount, int rowNumber) {
    for (int col = 0; col < colCount; col++) {
        insertNode(head, 0, rowNumber, col);
    }
    (*rowCount)++;
}

/**
 * @brief Função para inserir uma nova coluna na matriz
 * 
 * @param head 
 * @param rowCount 
 * @param colCount 
 * @param colNumber 
 */
void insertColumn(Matriz** head, int rowCount, int* colCount, int colNumber) {
    for (int row = 0; row < rowCount; row++) {
        insertNode(head, 0, row, colNumber);
    }
    (*colCount)++;
}