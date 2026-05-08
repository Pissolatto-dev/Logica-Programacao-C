#include <stdio.h>

int main() {

    int x;
    int y;

    printf("Insira dois valores distintos \n");
    scanf("%d %d", &x, &y);

    x < y ? printf("O maior é y \n") : printf ("O maior é x"); 

    return 0;
}