#include <stdio.h>

int main() {

    int vet[5];

    printf("Preencha o vetor de 5 elementos\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vet[i]);
    }

    int *p = vet;

    for (int i = 0; i < 5; i++) {
        *p = *p * 2;
        printf("%d  ", *(vet + i));
        p++;
    }

    return 0;
}