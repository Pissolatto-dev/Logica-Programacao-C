#include <stdio.h>

int expo(int n, int b) {

    if (n == 0) {
        return 1;
    }
    else {
        return b * expo(n-1, b);
    }
}

int main() {

    int n;
    int b;

    printf("Qual exponenciacão vc quer calcular? (implemente o expoente primeiro e depois a base)\n");
    scanf("%d %d", &n, &b);

    printf("Exponenciação de %d elevado a %d = %d", b, n, expo(n, b));

    return 0;
}