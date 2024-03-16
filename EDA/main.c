#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.c"

/**
 * @brief 
 * Função Main onde é inicializado o projeto
 * @return int 
 */
int main(void) {

    Alinea1();
    //Alinea2();
    //Alinea3();
    //Alinea4();

	return 0;
}

/**
 * @brief 
 * Função para executar alínea 1
 * @return int 
 */
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

/**
 * @brief 
 * Função para executar alínea 2
 * @return int 
 */
int Alinea2(void){

    // Carregar a matriz do ficheiro de texto
    Matriz* head = loadMatrixFromFile("matriz.txt");

    if (head == NULL) {
        fprintf(stderr, "Erro ao carregar a matriz do ficheiro.\n");
        return 1;
    }

    return 0;
}

/**
 * @brief Função para executar alínea 3
 * Utilizado o alínea 2 para carregar matriz do ficheiro para usar valores de teste
 * @return int 
 */
int Alinea3(){

    Matriz* head = loadMatrixFromFile("matriz.txt");

    if (head == NULL) {
        fprintf(stderr, "Erro ao carregar a matriz do ficheiro.\n");
        return 1;
    }

     // Modificar o valor de um nó específico (por exemplo, linha 1, coluna 1)
    modifyMatrizValue(head, 1, 1, 100);
    
    return 0;
}

/**
 * @brief Função apra executar alínea 4
 * Foi utilizado o código do alínea 2 para carregar uma matriz de dados 
 * @return int 
 */
int Alinea4(){

    Matriz* head = loadMatrixFromFile("matriz.txt");

    if (head == NULL) {
        fprintf(stderr, "Erro ao carregar a matriz do ficheiro.\n");
        return 1;
    }

    // Inserir uma nova linha na matriz
    int rowCount = 5; 
    int colCount = 5; 
    insertRow(&head, &rowCount, colCount, 2);

    // Inserir uma nova coluna na matriz
    insertColumn(&head, rowCount, &colCount, 3); // Inserir uma nova coluna na posição 3

return 0;
}