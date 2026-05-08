#include <stdio.h>

int main() {

    int x;
    int y;
    float result;
    int operation;

    printf("Qual operação entre 1 e 4 você pretende fazer? \n");
    scanf("%d", &operation);
    printf("Entre com dois valores diferentes de zero \n");
    scanf("%d %d", &x, &y);

    if (operation == 1) {
        result = (x + y) / 2;
        printf("O resultado é %f \n", result);
    }
    if (operation == 2) {
        result = x - y;
        printf("O resultado é %f \n", result);
    }
    if (operation == 3) {
        result = x * y;
        printf("O resultado é %f \n", result);
    }
    if (operation == 4) {
        result = x / y;
        printf("O resultado é %f \n", result);
    }

    return 0;

}