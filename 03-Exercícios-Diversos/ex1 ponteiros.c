#include <stdio.h>

int soma (int vet[], int tam) {

    int *p = vet;
    int s = 0;

    for (int i = 0; i < tam; i++) {
        s += p[i];
    }

    return s;
}

int main() {

    int s;
    int tam;

    printf("Quantos números você ira colocar??\n");
    scanf("%d", &tam);

    int vet[tam];
    printf("Coloque os números que quer somar\n");

    for (int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }

    s = soma(vet, tam);
    printf("A soma total é: %d", s);

    return 0;
}