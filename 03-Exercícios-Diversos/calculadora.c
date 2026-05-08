#include <stdio.h>

int main() {

    float x;
    float y;
    char operador; //Definir caracter

    printf("Digite um número, uma operação e outro número \n");
    scanf("%f %c %f", &x, &operador, &y);

    switch (operador) { //Cria quantos casos quiser
        
        case '+':
            printf("Adição = %.2f \n", x + y);
            break; //Faz o código parar e ir até o final
        case '-':
            printf("Subtração = %.2f \n", x - y);
            break;
        case '*':
            printf("Multiplicação = %.2f \n", x * y);
            break;
        case '/':
            printf("Divisão = %.2f \n", x / y);
            break;
        default: //Opcional
            printf("Operação desonhecida");
    }

    return 0;
}