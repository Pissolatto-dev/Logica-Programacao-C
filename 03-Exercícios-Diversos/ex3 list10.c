#include <stdio.h>
#include <stdlib.h>

void doub(int vet[], int n) {

    int *vet2;

    vet2 = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        vet2[i] = vet[i] * 2;
        printf("A previsão é de que o dia %d tenha %d de valor de produção.\n", i + 1, vet2[i]);
    }
}

int main() {

    int i, n;
    int *vet;

    printf("Qual a quantidade de dias?\n");
    scanf("%d", &n);

    vet = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Qual valor de produção no dia %d?\n", i + 1);
        scanf("%d", &vet[i]);
    }

    doub(vet, n);

    return 0;
}