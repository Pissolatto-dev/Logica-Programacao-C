#include <stdio.h>

int main() {

    float rodagem;
    float litros;
    char categoria;

    printf("Qual a categoria do seu veículo? \n");
    scanf(" %c", &categoria);
    printf("Quantos quilômetros você ira rodar? \n");
    scanf("%f", &rodagem);

    if (categoria == 'a') {
        litros = (rodagem / 15);
        printf("Você precisará de %f litros \n", litros);
    }
    if (categoria == 'b') {
        litros = (rodagem / 12);
        printf("Você precisará de %f litros \n", litros);
    }
    if (categoria == 'c') {
        litros = (rodagem / 10);
        printf("Você precisará de %f litros \n", litros);
    }

    return 0;
}