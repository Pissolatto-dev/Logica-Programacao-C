#include <stdio.h>
#include <stdlib.h>

int main() {

    int *array;
    int i;

    array = (int *) calloc(20, sizeof(int));

    if (array == NULL) {
        printf("Erro: Memória Insuficiente\n");
        exit(1);
    }

    for (i = 0; i < 20; i++) {
        array[i] = i;
    }

    for (i = 0; i < 20; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}