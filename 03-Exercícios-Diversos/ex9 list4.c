#include <stdio.h>

int mult(int x, int y) {

    int value = 0;
    for(int i = 1; i <= y; i++) {
        value += x;
    }
    return value;
}

int main() {

    int x;
    int y;
    int value;

    printf("Qual será a multiplicação?\n");
    scanf("%d %d", &x, &y);
    mult(x, y);
    printf("O resultado de %d x %d é: %d\n", x, y, mult(x, y));

    return 0;
}