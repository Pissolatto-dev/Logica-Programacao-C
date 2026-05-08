// [Gerenciamento de Memória] Alocação Dinâmica de Matrizes
// Objetivo: Criar e manipular matrizes bidimensionais com dimensões definidas em tempo de execução.
// Conceitos Aplicados: Ponteiros duplos (**mat), alocação dinâmica (malloc) e passagem de matrizes por função.

#include <stdio.h>
#include <stdlib.h>

void fillmat (int **mat, int n, int m) {

    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            mat[i][j] = (i + 1)+(j + 1);
        }
    }
}

void printmat (int **mat, int n, int m) {

    int i, j;

    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
    }
}

int main() {

    int **mat;
    int n, m, i, j;

    printf("Coloque quantas linhas e quantas colunas tera a matriz\n");
    scanf("%d %d", &n, &m);

    mat = (int **) malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        mat[i] = (int *) malloc(m * sizeof(int));
    }

    fillmat(mat, n, m);
    printmat(mat, n, m);


}