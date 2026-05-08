#include <stdio.h>

int main() {

    int peso;
    int altura;
    int IMC;

    printf("Qual seu peso?\n");
    scanf("%d", &peso);
    printf("Qual sua altura?\n");
    scanf("%d", &altura);

    IMC = peso / (altura * altura);
    
    if (imc < 18.5) {
        printf("Você está abaixo do peso\n");
    }
    else if(imc < 25) {
        printf("Você está no peso ideal\n");
    }
    else if(imc < 30) {
        printf("Você está com sobre peso\n");
    }
    else {
        printf("Você está com obesidade\n");
    }
    return 0;
}