#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.c"

int main(void) {

// Exemplo de matriz 3x3
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = NULL;

    // Criar a lista ligada com os valores da matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            insertNode(&head, matrix[i][j], i, j);
        }
    }

    // Encontrar a soma máxima
    int maxSum = findMaxSum(head);

    printf("A soma máxima possível é: %d\n", maxSum);

	return 0;
}