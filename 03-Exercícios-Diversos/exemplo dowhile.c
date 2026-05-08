#include <stdio.h>

int main() {

    int x;
    int y;
    int count;

    printf("Forneça um intervalo de x a y \n");
    scanf("%d %d", &x, &y);

    count = x+1;

    do {            //primeiro ele executa uma vez a ação para depois entrar em loop
        printf("%d \n", count);
        count++;
    } while(count < y);

    return 0;
}