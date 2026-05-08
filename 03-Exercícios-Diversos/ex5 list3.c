#include <stdio.h>

int main() {

    int x;
    int y;

    printf("Entre com os valores de x e y: \n");
    scanf("%d %d", &x, &y);

    if (x > y) {
        int aux = x;
        x = y;
        y = aux;
    }

    for (int i = x + 1; i < y; i++) {
        if (i % 5 == 2 || i % 2 ==3) {

        }
    }

    return 0;
}