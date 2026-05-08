#include <stdio.h>

int main() {

    int numero;

    printf("Informe um número inteiro \n");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("O número é par \n");
    }
    if (numero % 2 != 0) {
        printf("O número é ímpar \n");
    }
    if (numero >= 1) {
        printf("O número é positivo \n");
    }
    if (numero <= -1) {
        printf("O número é negativo \n");
    }
    if (numero = 0) {
        printf("O número é zero \n");
    }

    return 0;

}