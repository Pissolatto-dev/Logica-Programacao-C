#include <stdio.h>

int main() {

    int x;
    int y;
    int result = 0;

    printf("Entre com dois valores que queira multiplicar \n");
    scanf("%d %d", &x, &y);

    for (int i = 0; i <= x; i++) {
        result += y;
    }
    printf("Resultado: %d", result);
    return 0;
}