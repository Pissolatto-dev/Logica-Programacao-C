#include <stdio.h>

int main() {

    float idade;

    printf("Qual a sua idade? \n");
    scanf("%f", &idade);

    if (idade < 16) {
        printf("Você não pode votar \n");
    }
    else if (idade >= 18 && idade <= 65) {
        printf("Você é um eleitor obrigatório \n");
    }
    else if (idade > 16 && idade < 18 || idade > 65) {
        printf("Você é eleitor facultativo");
    }

    return 0;
}