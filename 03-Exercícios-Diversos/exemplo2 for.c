#include <stdio.h>

int main() {

    int fat;
    int n;
    int i;

    printf("Digite um número \n");
    scanf("%d", &n);
    fat = 1;

    for(i = n; i > 1; i--) {    //também é possível omitir a incialização (comando1) e o incremento (comando3)
        fat *= i;                   //óbvio que vai ter 2que moldar o programa para a omissão
    }
    printf("Fatorial de %d =%d \n", n, fat);

    return 0;
}   