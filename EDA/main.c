#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcoes.c"

int main(void) {

    Alinea1();

	return 0;
}

int Alinea1(void){

    // Exemplo de matriz 3x3
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matriz* head = NULL;

    // Criar a lista ligada com os valores da matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            insertMatriz(&head, matrix[i][j], i, j);
        }
    }

    // Encontrar a soma máxima
    int maxSum = findMaxSum(head);

    printf("A soma máxima possível é: %d\n", maxSum);

    return 0;
}

int Alinea2(void){

    // Carregar a matriz do arquivo de texto
    Matriz* head = loadMatrixFromFile("matriz.txt");

    if (head == NULL) {
        fprintf(stderr, "Erro ao carregar a matriz do arquivo.\n");
        return 1;
    }

    return 0;
}

int Alinea3(){
    
}