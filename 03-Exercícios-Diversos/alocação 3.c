#include <stdio.h>
#include <stdlib.h>

int main() {

    int *vet;
    int i;
    int n;
    int maior = 0;
    int menor = 100;

    printf("Qual a quantidade de alunos?\n");
    scanf("%d", &n);

    vet = (int *) malloc (n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Coloque a nota do aluno %d \n", i+1);
        scanf("%d", &vet[i]);
    }

    for (i = 0; i < n; i++) {
        if (maior < vet[i]) {
            maior = vet[i];
        }
    }
    
    for (i = 0; i < n; i++) {
        if (menor > vet[i]) {
            menor = vet[i];
        }
    }

    for (i = 0; i < n; i++) {
        if (maior == vet[i]) {
            printf("A maior nota é %d e pertence ao aluno %d \n", maior, i+1);
        }
    }

    for (i = 0; i < n; i++) {
        if (menor == vet[i]) {
            printf("A menor nota é %d e pertence ao aluno %d \n", menor, i+1);
        }
    }

    return 0;
}