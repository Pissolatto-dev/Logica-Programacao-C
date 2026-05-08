#include <stdio.h>

int main() {

    int altura;
    int idade;
    int count = 0;

    printf("Qual sua altura? (em centimetros) \n");
    scanf("%d", &altura);
    printf("Qual sua idade? \n");
    scanf("%d", &idade);

    if (idade >= 12 & altura >= 150) {
        count++;
    }
    if (idade >= 14 & altura >= 140) {
        count++;
    }
    if (idade >= 16 & altura >= 170) {
        count++;
    }
    printf("A quantidade de brinquedos que você pode andar é %d \n", count);

    return 0;
}