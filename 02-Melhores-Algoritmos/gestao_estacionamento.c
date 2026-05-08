// [Algoritmos de Aplicação] Sistema de Monitoramento de Vagas
// Objetivo: Mapear e contabilizar diferentes tipos de veículos em um estacionamento utilizando matrizes.
// Conceitos Aplicados: Lógica de matrizes, contadores acumulativos e estruturas condicionais encadeadas.

#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, n, j;
    int ca, cv, cc;
    int **vet;

    printf("Quantas vagas possui o estacionamento?\n");
    scanf("%d", &n);

    vet = (int **) malloc(1 * sizeof(int *));
    
    for (i = 0; i < 1; i++) {
        vet[i] = (int *) malloc(n * sizeof(int));
    }

    printf("Preencha o estado das vagas usando\n0 = vazio\n1 = carro\n2 = caminhonete\n");

    for (i = 0; i < 1; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &vet[i][j]);
        }
    }

    for (i = 0; i < 1; i++) {
        for (j = 0; j < n; j++) {
            if (vet[i][j] == 0) {
                cv++;
            }
            else if (vet[i][j] == 1) {
                ca++;
            }
            else if (vet[i][j] == 2) {
                cc++;
            }
        }
    }

    printf("O total de vagas de carros é: %d\n", ca);
    printf("O total de vagas de caminhonete é: %d\n", cc);
    printf("O total de vagas vazias é: %d\n", cv);

    return 0;
}
