#include <stdio.h>

int main() {

    int number;
    int divisores;

    divisores = 0;
    printf("Entre com um número inteiro \n");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            printf("%d\n", i);
            divisores++;
        }
    }

    printf("\nQuantidade de divisores de %d: %d \n", number, divisores);
    return 0;
}