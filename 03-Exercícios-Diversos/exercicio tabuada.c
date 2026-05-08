#include <stdio.h>

int main() {

    int n;
    int tabuada;
    int x;
    x = 0;

    printf("Informa um número que deseja a tabuada \n");
    scanf("%d", &n);

    while(x <= 10) {
        tabuada = n*x;
        printf("%d*%d = %d \n", n, x, tabuada);
        x++;
    }

    return 0;

}