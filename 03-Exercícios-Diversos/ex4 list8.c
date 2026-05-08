#include <stdio.h>

int main() {
    
    int n;

    printf("Qual a quantidade de números?\n");
    scanf("%d", &n);

    int vet[n];
    int *p = vet;

    printf("Coloque os números do vetor\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < (n / 2); i++) {
        printf("%d \n", p[i]);
    }

    for (int i = n; i > (n / 2); i--) {
        printf("%d \n", p[i]);
    }

    return 0;
}