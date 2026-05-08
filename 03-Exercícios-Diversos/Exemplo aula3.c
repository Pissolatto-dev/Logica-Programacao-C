#include <stdio.h>

int main() {

    int x;
    int y;
    int count;

    printf("Entre com um intervalo de x a y: \n");
    scanf("%d %d", &x, &y);

    count = x + 1;
    while (count < y) {
        printf("\n %d", count);
        count++;
    }

    return 0;
}