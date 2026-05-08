#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    int *vet;
    int total = 0;
    int maior = 0;

    vet = (int *) malloc(7 * sizeof(int));

    for (i = 0; i < 7; i++) {
        printf("Qual o gasto do dia %d?\n", i + 1);
        scanf("%d", &vet[i]);
    }

    for (i = 0; i < 7; i++) {
        total += vet[i];
        if (vet[i] >= maior) {
            maior = vet[i];
        }
    }

    for (i = 0; i < 7; i++) {
        if (vet[i] == maior) {
            printf("O dia com mais gasto foi o dia %d, com %d reais gastos\n", i + 1, maior);
        }
    }
    printf("Total gasto na semana = %d\n", total);

    return 0;
}