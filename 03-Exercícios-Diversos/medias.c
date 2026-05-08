#include <stdio.h>

int main(){

    float salario;

    printf("Qual seu salário? \n");
    scanf("%f", &salario);

    if (salario <= 1000) {
        salario = salario * 1.15; // aumento 15%
    }
    else if (salario > 1000 && salario <= 2000) {
        salario = salario * 1.10; // aumento 10%
    }
    else if (salario > 2000) {
        salario = salario * 1.05; // aumento de 5%
    }

    printf("Seu novo salário é de %f \n", salario);

    return 0;
}