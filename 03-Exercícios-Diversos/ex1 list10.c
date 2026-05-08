#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, n;
    int *vet;

    printf("Qual a quantidade de mensagens?\n");
    scanf("%d", &n);
    getchar();

    vet = (int *) malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }
    
    printf("\n");

    for (i = n; i > 0; i--) {
        printf("%d \n", vet[i - 1]);
    }

    return 0;
}