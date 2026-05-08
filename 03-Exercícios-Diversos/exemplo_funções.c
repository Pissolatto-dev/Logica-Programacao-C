#include <stdio.h>

float bigger3 (int a, int b, int c) {

    if (a > b & a > c) {
        return a;
    }
    else if (b > a && b > c) {
        return b;
    }
    else {
        return c;
    }
}

int main() {

    int x;
    int y;
    int z;
    int resultado;
    scanf("%d %d %d", &x, &y, &z);
    resultado = bigger3(x, y, z);
    printf("\nMaior número: %d\n", resultado);

    return 0;
}
