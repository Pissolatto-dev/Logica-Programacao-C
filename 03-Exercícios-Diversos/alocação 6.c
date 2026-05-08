#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, j, n, m;
    int maior = 0;
    int menor;
    int **p;
    int total;
    float media;
    p = (int **) malloc(n * sizeof(int *));

    printf("Qual a quantidade de alunos?\n");
    scanf("%d", &n);

    printf("Qual a quantidade de notas?\n");
    scanf("%d", &m);

    for (i = 0; i < n; i++) {
        p[i] = (int *) malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        printf("Coloque as notas do aluno %d\n", i+1);
        for (j = 0; j < m; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    printf("Notas dos alunos\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++) {
            printf("%d ", p[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (maior < p[i][j]) {
                maior = p[i][j];
            }
        }
    }
    printf("\nA Maior nota foi %d \n", maior);
    
    menor = maior;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (menor > p[i][j]) {
                menor = p[i][j];
            }
        }
    }
    printf("A Menor nota foi %d \n", menor);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < m; j++) {
            total += p[i][j];
        }
    }
    media = total / (n * m);

    printf("Média de notas: %2.f \n", media);

    return 0;
}