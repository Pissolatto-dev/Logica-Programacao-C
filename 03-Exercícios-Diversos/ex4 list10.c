#include <stdio.h>
#include <stdlib.h>

int main() {

    int i = 0;
    int j = 0;
    int *vet;

    vet = (int *) malloc(0 * sizeof(int));

    while (1) {

        vet = (int *) realloc(vet, i+1 * sizeof(int));

        scanf("%d", &vet[i]);

        if (vet[i] < 0) {
            break;
        }
        i++;
    }

    printf("Ordem dos números: \n");

    while (1) {

        if (vet[j] < 0) {
            break;
        }

        printf("%d  ", vet[j]);
        j++;
    }

    return 0;
}