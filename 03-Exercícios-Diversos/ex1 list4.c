#include <stdio.h>

float calculate(float peso, float altura) {
    return peso / (altura * altura);
}

void classificar(float imc) {
    if (imc <= 18.5) {
        printf("abaixo do peso\n");
    }
    else if (imc <= 24.9) {
        printf("peso normal\n");
    }
    else if (imc <= 29.9) {
        printf("sobrepeso\n");
    }
    else {
        printf("obeso\n");
    }
}

int main() {
    
    float peso;
    float altura;
    float imc;

    printf("informe sua altura e peso\n");
    scanf("%d %d", &altura, &peso);
    imc = calculate(peso, altura);
    printf("IMC: %.2f\n", imc);
    classificar (imc);

    return 0;
}